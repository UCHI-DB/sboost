//
// Created by harper on 9/30/19.
//

#ifndef SBOOST_SBOOST_H
#define SBOOST_SBOOST_H

#include <cstdint>
#include <functional>
#include <immintrin.h>
#include "unpacker.h"

namespace sboost {

    class Bitpack {
    protected:
        uint32_t bitWidth;
        uint32_t target;
        uint32_t target2;
        uint64_t extract;

        __m512i mask;
        __m512i msbmask;
        __m512i spanned;
        __m512i nspanned;
        __m512i l2;
        __m512i g2;

        __m512i spanned2;
        __m512i nspanned2;
        __m512i l22;
        __m512i g22;
    public:
        Bitpack(uint32_t bitWidth, uint32_t target);

        Bitpack(uint32_t bitWidth, uint32_t t1, uint32_t t2);

        virtual ~Bitpack();

        void equal(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset);

        void less(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset);

        void leq(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset);

        void greater(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset);

        void geq(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset);

        void rangele(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset);

        void between(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset);
    };

    class BitpackCompare {
    protected:
        uint32_t bit_width_;
        uint64_t extract_;

        __m512i mask_;
        __m512i msbmask_;
    public:
        BitpackCompare(uint32_t bitWidth);

        virtual ~BitpackCompare() = default;

        void less(const uint8_t *left, const uint8_t *right, uint32_t numEntry, uint64_t *res, uint32_t resoffset);
    };

    using namespace std;

    const auto ZERO = _mm256_set1_epi64x(0);
    const auto IDX = _mm256_setr_epi32(8, 0, 1, 2, 3, 4, 5, 6);
    const auto IDX2 = _mm256_setr_epi32(0, 8, 2, 8, 1, 4, 3, 6);
//    const auto IDX3 = _mm256_setr_epi32(8,8,8,8,0,1,2,3);
    const auto INV = _mm256_setr_epi32(3, 2, 1, 0, 7, 6, 5, 4);

    inline __m256i cumsum32(__m256i b) {
        __m256i bp = _mm256_permutex2var_epi32(b, IDX, ZERO);
        __m256i s1 = _mm256_hadd_epi32(b, bp);
        __m256i s2 = _mm256_permutex2var_epi32(s1, IDX2, ZERO);
        __m256i s3 = _mm256_hadd_epi32(s1, s2);
        __m256i s4 = _mm256_permute2x128_si256(s3, ZERO, 0x2);
        __m256i result = _mm256_add_epi32(s3, s4);
        return _mm256_permutevar8x32_epi32(result, INV);
    }
}
#endif //SBOOST_SBOOST_H
