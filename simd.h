//
// Created by harper on 3/17/20.
//

#ifndef ARROW_SIMD_H
#define ARROW_SIMD_H

#include <cstdint>

namespace sboost {

    namespace simd {

        void simd_or(uint64_t *a, uint64_t *b, uint32_t size);

        void simd_and(uint64_t *a, uint64_t *b, uint32_t size);
    }
}


#endif //ARROW_SIMD_H
