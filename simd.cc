//
// Created by harper on 3/17/20.
//

#include "simd.h"
#include <immintrin.h>

namespace sboost {

    namespace simd {

        void simd_or(uint64_t *a, uint64_t *b, uint32_t size) {
            uint32_t loop = size >> 3;
            uint64_t *inout = a;
            uint64_t *in = b;
            for (uint32_t i = 0; i < loop; ++i) {
                _mm512_store_si512((void *) inout, _mm512_or_si512(_mm512_load_si512((const void *) inout),
                                                                   _mm512_load_si512((const void *) in)));
                inout += 8;
                in += 8;
            }
            uint32_t remain = size & 0x7;
            for (uint32_t i = 0; i < remain; ++i) {
                *inout |= *in;
                inout++;
                in++;
            }
        }

        void simd_and(uint64_t *a, uint64_t *b, uint32_t size) {
            uint32_t loop = size >> 3;
            uint64_t *inout = a;
            uint64_t *in = b;
            for (uint32_t i = 0; i < loop; ++i) {
                _mm512_store_si512((void *) inout, _mm512_and_si512(_mm512_load_si512((const void *) inout),
                                                                    _mm512_load_si512((const void *) in)));
                inout += 8;
                in += 8;
            }
            uint32_t remain = size & 0x7;
            for (uint32_t i = 0; i < remain; ++i) {
                *inout &= *in;
                inout++;
                in++;
            }
        }
    }
}