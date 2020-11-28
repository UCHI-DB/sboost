//
// Created by harper on 9/14/19.
//

#include <cstdint>
#include "rlehybrid.h"
#include "../bitmap_writer.h"
#include "../byteutils.h"
#include "../sboost.h"
#include "encoding_utils.h"

namespace sboost {
    namespace encoding {
        namespace rlehybrid {

            SegmentReader::SegmentReader(const uint8_t *data, uint32_t bit_width, uint32_t num_entry)
                    : data_(data), bit_width_(bit_width), num_entry_(num_entry),
                      pointer_(0), counter_(0) {}

            bool SegmentReader::hasNext() {
                return counter_ < num_entry_;
            }

            Segment SegmentReader::next() {
                uint32_t header = byteutils::readUnsignedVarInt(data_, &pointer_);
                Segment segment;
                segment.mode_ = (header & 1) == 0 ? RLE : PACKED;
                switch (segment.mode_) {
                    case RLE: {
                        segment.num_entry_ = header >> 1;
                        segment.value_ = byteutils::readIntLittleEndianPaddedOnBitWidth(data_, &pointer_, bit_width_);
                        break;
                    }
                    case PACKED: {
                        int numGroups = header >> 1;
                        segment.num_entry_ = numGroups << 3;
                        segment.data_ = data_ + pointer_;
                        segment.data_length_ = numGroups * bit_width_;
                        pointer_ += numGroups * bit_width_;
                        break;
                    }
                }
                counter_ += segment.num_entry_;
                return segment;
            }

            template<typename PRED>
            void process(const uint8_t *input,
                         uint64_t *output, uint32_t outputOffset,
                         uint32_t bitWidth, uint32_t numEntry, PRED pred) {
                uint32_t pointer = 0;
                uint32_t counter = 0;
                uint32_t currentCount = 0;
                int currentValue = 0;
                MODE mode;

                BitmapWriter bitmap(output, outputOffset);

                while (counter < numEntry) {
                    uint32_t header = byteutils::readUnsignedVarInt(input, &pointer);
                    mode = (header & 1) == 0 ? RLE : PACKED;
                    switch (mode) {
                        case RLE: {
                            currentCount = header >> 1;
                            currentValue = byteutils::readIntLittleEndianPaddedOnBitWidth(input, &pointer, bitWidth);
                            uint8_t bit = pred.test(currentValue);
                            bitmap.appendBits(bit, currentCount);
                            break;
                        }
                        case PACKED: {
                            int numGroups = header >> 1;
                            currentCount = numGroups << 3;
                            pred.test(input + pointer, currentCount, output, bitmap.offset());
                            pointer += numGroups * bitWidth;
                            bitmap.moveForward(currentCount);
                            break;
                        }
                    }
                    counter += currentCount;
                }
                encoding::cleanup(counter, numEntry, output, outputOffset);
            }

            class EqualPred {
            protected:
                uint32_t target_;
                sboost::Bitpack sboost_;
            public:
                EqualPred(uint32_t bitWidth, uint32_t target) : target_(target), sboost_(bitWidth, target) {}

                inline bool test(int32_t value) {
                    return (int32_t) target_ == value;
                }

                inline void test(const uint8_t *data, uint32_t numEntry, uint64_t *bitmap, uint32_t bitmap_offset) {
                    sboost_.equal(data, numEntry, bitmap, bitmap_offset);
                }
            };

            void equal(const uint8_t *input,
                       uint64_t *output, uint32_t outputOffset,
                       uint32_t bitWidth, uint32_t numEntry, uint32_t value) {
                EqualPred pred(bitWidth, value);
                process<EqualPred>(input, output, outputOffset, bitWidth, numEntry, pred);
            }

            class LessPred {
            protected:
                uint32_t target_;
                sboost::Bitpack sboost_;
            public:
                LessPred(uint32_t bitWidth, uint32_t target) : target_(target), sboost_(bitWidth, target) {}

                inline bool test(int32_t value) {
                    return value < (int32_t) target_;
                }

                inline void test(const uint8_t *data, uint32_t numEntry, uint64_t *bitmap, uint32_t bitmap_offset) {
                    sboost_.less(data, numEntry, bitmap, bitmap_offset);
                }
            };

            void less(const uint8_t *input,
                      uint64_t *output, uint32_t outputOffset,
                      uint32_t bitWidth, uint32_t numEntry, uint32_t value) {
                LessPred pred(bitWidth, value);
                process<LessPred>(input, output, outputOffset, bitWidth, numEntry, pred);
            }

            class GreaterPred {
            protected:
                uint32_t target_;
                sboost::Bitpack sboost_;
            public:
                GreaterPred(uint32_t bitWidth, uint32_t target) : target_(target), sboost_(bitWidth, target) {}

                inline bool test(int32_t value) {
                    return value > (int32_t) target_;
                }

                inline void test(const uint8_t *data, uint32_t numEntry, uint64_t *bitmap, uint32_t bitmap_offset) {
                    sboost_.greater(data, numEntry, bitmap, bitmap_offset);
                }
            };

            void greater(const uint8_t *input,
                         uint64_t *output, uint32_t outputOffset,
                         uint32_t bitWidth, uint32_t numEntry, uint32_t value) {
                GreaterPred pred(bitWidth, value);
                process<GreaterPred>(input, output, outputOffset, bitWidth, numEntry, pred);
            }

            class RangelePred {
            protected:
                uint32_t lower_;
                uint32_t upper_;
                sboost::Bitpack sboost_;
            public:
                RangelePred(uint32_t bitWidth, uint32_t lower, uint32_t upper)
                        : lower_(lower), upper_(upper), sboost_(bitWidth, lower, upper) {}

                inline bool test(int32_t value) {
                    uint32_t uvalue = static_cast<uint32_t>(value);
                    return uvalue >= lower_ && uvalue < upper_;
                }

                inline void test(const uint8_t *data, uint32_t numEntry, uint64_t *bitmap, uint32_t bitmap_offset) {
                    sboost_.rangele(data, numEntry, bitmap, bitmap_offset);
                }
            };

            void rangele(const uint8_t *input,
                         uint64_t *output, uint32_t outputOffset,
                         uint32_t bitWidth, uint32_t numEntry, uint32_t lower, uint32_t upper) {
                RangelePred pred(bitWidth, lower, upper);
                process<RangelePred>(input, output, outputOffset, bitWidth, numEntry, pred);
            }

            class BetweenPred {
            protected:
                uint32_t lower_;
                uint32_t upper_;
                sboost::Bitpack sboost_;
            public:
                BetweenPred(uint32_t bitWidth, uint32_t lower, uint32_t upper)
                        : lower_(lower), upper_(upper), sboost_(bitWidth, lower, upper) {}

                inline bool test(int32_t value) {
                    uint32_t uvalue = static_cast<uint32_t>(value);
                    return uvalue >= lower_ && uvalue <= upper_;
                }

                inline void test(const uint8_t *data, uint32_t numEntry, uint64_t *bitmap, uint32_t bitmap_offset) {
                    sboost_.between(data, numEntry, bitmap, bitmap_offset);
                }
            };


            void between(const uint8_t *input,
                         uint64_t *output, uint32_t outputOffset,
                         uint32_t bitWidth, uint32_t numEntry, uint32_t lower, uint32_t upper) {
                BetweenPred pred(bitWidth, lower, upper);
                process<BetweenPred>(input, output, outputOffset, bitWidth, numEntry, pred);
            }
        }
    }
}