//
// Created by harper on 2/18/20.
//
#include "deltabp.h"
#include "../byteutils.h"
#include "../unpacker.h"
#include "../sboost.h"
#include "../bitmap_writer.h"

namespace sboost {
    namespace encoding {
        namespace deltabp {

            using namespace std;
            using namespace std::placeholders;

            /**
             * Process a Delta BitPacking Input using SBoost
             *
             * @param input
             * @param offset
             * @param output
             * @param output_offset
             * @param bit_width
             * @param num_entry
             * @param processor
             */
            template<typename PRED>
            uint32_t process(const uint8_t *input, uint64_t *output,
                             uint32_t output_offset, uint32_t num_entry,
                             PRED &pred) {
                BitmapWriter bitmap(output, output_offset);

                // Read Block Size and Num of mini Blocks
                uint32_t read_pos = 0;
                uint32_t block_size = byteutils::readUnsignedVarInt(input, &read_pos);
                uint32_t num_miniblock = byteutils::readUnsignedVarInt(input, &read_pos);
                byteutils::readUnsignedVarInt(input, &read_pos);
                uint32_t miniblock_size = block_size / num_miniblock;

                uint32_t bit_widths[num_miniblock];

                int64_t last_value = byteutils::readZigZagVarLong(input, &read_pos);

                // Process the first value
                uint8_t res = pred.apply(last_value);
                bitmap.appendBits(res, 1);

                uint32_t processed = 1;
                while (processed < num_entry) {
                    // Load and process block
                    int64_t min_delta = byteutils::readZigZagVarLong(input, &read_pos);
                    __m256i mdelta = _mm256_set1_epi32(min_delta);
                    for (uint32_t i = 0; i < num_miniblock; ++i) {
                        bit_widths[i] = input[read_pos++];
                    }
                    // mini block is atomic for reading, we read a mini block when there are more values left
                    for (uint32_t i = 0; i < num_miniblock && processed < num_entry; ++i) {
                        auto unpacker = sboost::unpackers[(bit_widths[i])];
                        for (uint32_t j = 0; j < miniblock_size; j += 8) {
                            __m256i unpacked = unpacker->unpack(input + read_pos);
                            __m256i delta = _mm256_add_epi32(unpacked, mdelta);
                            __m256i csum = cumsum32(delta);
                            __m256i final = _mm256_add_epi32(csum, _mm256_set1_epi32(last_value));

                            uint8_t result = pred.apply(final);
                            bitmap.appendByte(result);
                            last_value = (final[3] >> 32) & 0xFFFFFFFF;
                            read_pos += bit_widths[i];
                        }
                    }
                    processed += block_size;
                }
                return read_pos;
            }

            class EqualPred {
            private:
                int32_t target_;
                __m256i target256_;
            public:
                EqualPred(int32_t target) : target_(target), target256_(_mm256_set1_epi32(target)) {}

                inline bool apply(int32_t val) {
                    return val == target_;
                }

                inline uint8_t apply(__m256i val) {
                    return _mm256_cmp_epi32_mask(val, target256_, 0);
                }
            };

            uint32_t equal(const uint8_t *input, uint64_t *output, uint32_t output_offset,
                           uint32_t num_entry, int32_t value) {
                EqualPred pred(value);
                return process<EqualPred>(input, output, output_offset, num_entry, pred);
            }

            class LessPred {
            private:
                int32_t target_;
                __m256i target256_;
            public:
                LessPred(int32_t target) : target_(target), target256_(_mm256_set1_epi32(target)) {}

                inline bool apply(int32_t val) {
                    return val < target_;
                }

                inline uint8_t apply(__m256i val) {
                    return _mm256_cmp_epi32_mask(val, target256_, 1);
                }
            };

            uint32_t less(const uint8_t *input, uint64_t *output, uint32_t output_offset,
                          uint32_t num_entry, int32_t value) {
                LessPred pred(value);
                return process<LessPred>(input, output, output_offset, num_entry, pred);
            }

            class GreaterPred {
            private:
                int32_t target_;
                __m256i target256_;
            public:
                GreaterPred(int32_t target) : target_(target), target256_(_mm256_set1_epi32(target)) {}

                inline bool apply(int32_t val) {
                    return val > target_;
                }

                inline uint8_t apply(__m256i val) {
                    return _mm256_cmp_epi32_mask(val, target256_, 6);
                }
            };

            uint32_t greater(const uint8_t *input, uint64_t *output, uint32_t output_offset,
                             uint32_t num_entry, int32_t value) {
                GreaterPred pred(value);
                return process<GreaterPred>(input, output, output_offset, num_entry, pred);
            }

            class BetweenPred {
            private:
                int32_t lb_;
                int32_t ub_;
                __m256i lb256_;
                __m256i ub256_;
            public:
                BetweenPred(int32_t lb, int32_t ub) : lb_(lb), ub_(ub),
                                                      lb256_(_mm256_set1_epi32(lb)),
                                                      ub256_(_mm256_set1_epi32(ub)) {}

                inline bool apply(int32_t val) {
                    return val >= lb_ && val <= ub_;
                }

                inline uint8_t apply(__m256i val) {
                    return _mm256_cmp_epi32_mask(val, lb256_, 5)
                           & _mm256_cmp_epi32_mask(val, ub256_, 2);
                }
            };

            uint32_t between(const uint8_t *input, uint64_t *output, uint32_t output_offset,
                             uint32_t num_entry, int32_t lb, int32_t ub) {
                BetweenPred pred(lb, ub);
                return process<BetweenPred>(input, output, output_offset, num_entry, pred);
            }

            class RangelePred {
            private:
                int32_t lb_;
                int32_t ub_;
                __m256i lb256_;
                __m256i ub256_;
            public:
                RangelePred(int32_t lb, int32_t ub) : lb_(lb), ub_(ub),
                                                      lb256_(_mm256_set1_epi32(lb)),
                                                      ub256_(_mm256_set1_epi32(ub)) {}

                inline bool apply(int32_t val) {
                    return val >= lb_ && val < ub_;
                }

                inline uint8_t apply(__m256i val) {
                    return _mm256_cmp_epi32_mask(val, lb256_, 5)
                           & _mm256_cmp_epi32_mask(val, ub256_, 1);
                }
            };

            uint32_t rangele(const uint8_t *input, uint64_t *output, uint32_t output_offset,
                             uint32_t num_entry, int32_t lb, int32_t ub) {
                RangelePred pred(lb, ub);
                return process<RangelePred>(input, output, output_offset, num_entry, pred);
            }
        }
    }
}