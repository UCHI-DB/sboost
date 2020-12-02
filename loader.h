//
// Created by Hao Jiang on 12/1/20.
//

#ifndef SBOOST_LOADER_H
#define SBOOST_LOADER_H

#include <cstdint>
#include <immintrin.h>

namespace sboost {
    namespace loader {

        extern void (*loaders[32])(const uint8_t *, uint64_t *);
        extern void (*writers[32])(__m512i,uint64_t*,uint64_t);

        extern uint32_t entryInBlocks[32][8];
    }
}

#endif //SBOOST_LOADER_H
