//
// Created by harper on 3/15/18.
//

#include <cassert>
#include <vector>
#include "unpacker.h"

namespace sboost {
    using namespace std;

    Small32Unpacker::Small32Unpacker(uint32_t es) : entrySize_(es) {
        assert(es < 26);
        if (es == 0) {
            return;
        }

        this->shuffleInst_ = (__m256i *) aligned_alloc(32, 32 * 8);
        this->shiftInst_ = (__m256i *) aligned_alloc(32, 32 * 8);

        this->mask_ = (__m256i *) aligned_alloc(32, 32);
        mask_[0] = _mm256_set1_epi32((1 << es) - 1);

        __m128i *shuffleBuffer = (__m128i *) aligned_alloc(16, 16 * 8);
        __m128i *shiftBuffer = (__m128i *) aligned_alloc(16, 16 * 8);
        uint32_t *shuffleDataBuffer = (uint32_t *) aligned_alloc(16, 16);
        uint32_t *shiftDataBuffer = (uint32_t *) aligned_alloc(16, 16);

        nextPos_ = (entrySize_ * 4) / 8;
        int higher = (entrySize_ * 4) % 8;
        // Compute shuffle and shift instructions
        std::vector<int> cand{0, higher};
        for (int const &offset : cand) {
            for (int idx = 0; idx < 4; idx++) {
                uint32_t entryoff = offset + entrySize_ * idx;
                shiftDataBuffer[idx] = entryoff % 8;

                uint8_t round = (shiftDataBuffer[idx] + entrySize_ - 1) / 8;
                shuffleDataBuffer[idx] = 0;
                uint32_t start = entryoff / 8;
                for (uint32_t bi = 0; bi <= round; bi++) {
                    shuffleDataBuffer[idx] |= (start + bi) << (bi * 8);
                }
                for (uint32_t bi = round + 1; bi < 4; bi++) {
                    shuffleDataBuffer[idx] |= 0xff << bi * 8;
                }
            }

            shuffleBuffer[offset] = _mm_load_si128((__m128i *) shuffleDataBuffer);
            shiftBuffer[offset] = _mm_load_si128((__m128i *) shiftDataBuffer);
        }

        // Combine them to make 256-bit shuffle and shift instructions
        this->shuffleInst_[0] = _mm256_set_m128i(shuffleBuffer[higher], shuffleBuffer[0]);
        this->shiftInst_[0] = _mm256_set_m128i(shiftBuffer[higher], shiftBuffer[0]);

        free(shuffleDataBuffer);
        free(shiftDataBuffer);
        free(shuffleBuffer);
        free(shiftBuffer);
    }

    Small32Unpacker::~Small32Unpacker() {
        free(shuffleInst_);
        free(mask_);
        free(shiftInst_);
    }

    __m256i Small32Unpacker::unpack(const uint8_t *data) {
        // Load data into 2 128 buffer and combine as 256
        __m256i main = _mm256_loadu2_m128i((__m128i *) (data + nextPos_), (__m128i *) data);
        // Shuffle
        __m256i shuffle = _mm256_shuffle_epi8(main, shuffleInst_[0]);
        // Shift
        __m256i shift = _mm256_srlv_epi32(shuffle, shiftInst_[0]);
        // Mask
        return _mm256_and_si256(shift, mask_[0]);
    }


    Large32Unpacker::Large32Unpacker(uint32_t es) : entrySize_(es) {
        assert(es >= 26 && es < 32);

        shiftInst_ = (__m512i *) aligned_alloc(64, 8 * 64);
        shuffleInst_ = (__m512i *) aligned_alloc(64, 8 * 64);

        mask_ = (__m256i *) aligned_alloc(32, 32);
        mask_[0] = _mm256_set1_epi32((1u << entrySize_) - 1);

        __m128i *shuffleBuffer = (__m128i *) aligned_alloc(16, 16 * 8);
        __m128i *shiftBuffer = (__m128i *) aligned_alloc(16, 16 * 8);
        uint64_t *shuffleDataBuffer = (uint64_t *) aligned_alloc(16, 16);
        uint64_t *shiftDataBuffer = (uint64_t *) aligned_alloc(16, 16);

        for (int j = 0; j < 3; j++) {
            nextPos_[j] = (entrySize_ * 2 * (j + 1)) / 8;
        }

        int i = 0;
        int high = (i + entrySize_ * 2) % 8;
        int higher = (high + entrySize_ * 2) % 8;
        int evenHigher = (higher + entrySize_ * 2) % 8;

        // Compute shuffle and shift instructions
        for (int offset : {i, high, higher, evenHigher}) {
            for (int idx = 0; idx < 2; idx++) {
                uint32_t entryoff = offset + entrySize_ * idx;
                shiftDataBuffer[idx] = entryoff % 8;

                uint8_t round = (shiftDataBuffer[idx] + entrySize_) / 8;
                shuffleDataBuffer[idx] = 0;
                uint64_t start = entryoff / 8;
                for (int bi = 0; bi <= round; bi++) {
                    shuffleDataBuffer[idx] |= (start + bi) << bi * 8;
                }
                for (int bi = round + 1; bi < 8; bi++) {
                    shuffleDataBuffer[idx] |= 0xffL << bi * 8;
                }
            }


            shuffleBuffer[offset] = _mm_load_si128((__m128i *) shuffleDataBuffer);
            shiftBuffer[offset] = _mm_load_si128((__m128i *) shiftDataBuffer);
        }

        // Combine them to make 512-bit shuffle and shift instructions

        __m128i su0 = shuffleBuffer[i];
        __m128i su1 = shuffleBuffer[high];
        __m128i su2 = shuffleBuffer[higher];
        __m128i su3 = shuffleBuffer[evenHigher];

        __m512i shuffle = _mm512_castsi128_si512(su0);
        shuffle = _mm512_inserti64x2(shuffle, su1, 1);
        shuffle = _mm512_inserti64x2(shuffle, su2, 2);
        shuffle = _mm512_inserti64x2(shuffle, su3, 3);
        this->shuffleInst_[0] = shuffle;

        __m128i sh0 = shiftBuffer[i];
        __m128i sh1 = shiftBuffer[high];
        __m128i sh2 = shiftBuffer[higher];
        __m128i sh3 = shiftBuffer[evenHigher];

        __m512i shift = _mm512_castsi128_si512(sh0);
        shift = _mm512_inserti64x2(shift, sh1, 1);
        shift = _mm512_inserti64x2(shift, sh2, 2);
        shift = _mm512_inserti64x2(shift, sh3, 3);
        this->shiftInst_[i] = shift;


        free(shuffleDataBuffer);
        free(shiftDataBuffer);
        free(shuffleBuffer);
        free(shiftBuffer);
    }

    Large32Unpacker::~Large32Unpacker() {
        free(shiftInst_);
        free(shuffleInst_);
        free(mask_);
    }

    __m256i Large32Unpacker::unpack(const uint8_t *data) {
        // Load 4 128 bit into a 512 bit register
        __m256i lower = _mm256_loadu2_m128i((__m128i *) (data + nextPos_[0]), (__m128i *) data);
        __m256i higher = _mm256_loadu2_m128i((__m128i *) (data + nextPos_[2]),
                                             (__m128i *) (data + nextPos_[1]));
        // Get a single 512 bit
        __m512i main = _mm512_castsi256_si512(lower);
        main = _mm512_inserti64x4(main, higher, 1);

        // Shuffle
        __m512i shuffle = _mm512_shuffle_epi8(main, shuffleInst_[0]);
        // Shift
        __m512i shift = _mm512_srlv_epi64(shuffle, shiftInst_[0]);
        // Mask
        return _mm256_and_si256(_mm512_cvtepi64_epi32(shift), mask_[0]);
    }

    void unpackScalar(const uint8_t *input, uint32_t numEntry, uint8_t bitWidth, uint32_t *output) {
        uint32_t index = 0;
        uint8_t offset = 0;
        uint32_t mask = (1u << bitWidth) - 1;
        const uint64_t *view = (const uint64_t *) input;
        for (uint32_t i = 0; i < numEntry; ++i) {
            output[i] = static_cast<uint32_t>((view[index] >> offset) & mask);
            offset += bitWidth;
            index += offset >> 6;
            if (offset > 64) {
                int extra = offset - 64;
                output[i] |= ((view[index] & ((1 << extra) - 1))) << (bitWidth - extra);
            }
            offset &= 0x3F;
        }
    }
}