//
// Created by harper on 2/18/20.
//

#ifndef SBOOST_ENCODING_DELTABP_H
#define SBOOST_ENCODING_DELTABP_H

#include <immintrin.h>
#include <cstdint>
#include <functional>

namespace sboost {
    namespace encoding {
        namespace deltabp {

            uint32_t equal(const uint8_t *, uint64_t *, uint32_t, uint32_t, int32_t);

            uint32_t less(const uint8_t *, uint64_t *, uint32_t, uint32_t, int32_t);

            uint32_t greater(const uint8_t *, uint64_t *, uint32_t, uint32_t, int32_t);

            uint32_t between(const uint8_t *, uint64_t *, uint32_t, uint32_t, int32_t, int32_t);

            uint32_t rangele(const uint8_t *, uint64_t *, uint32_t, uint32_t, int32_t, int32_t);
        }
    }
}

#endif //SBOOST_ENCODING_DELTABP_H
