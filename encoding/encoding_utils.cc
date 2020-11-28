//
// Created by harper on 10/21/19.
//

#include "encoding_utils.h"

namespace sboost {
    namespace encoding {

        void cleanup(uint32_t counter, uint32_t numEntry, uint64_t *output, uint32_t outputOffset) {
            if (counter > numEntry) {
                // Erase off extra entries
                uint32_t eraseOffset = outputOffset + numEntry;
                uint32_t eraseIndex = eraseOffset >> 6;
                eraseOffset &= 0x3F;
                output[eraseIndex] &= (1L << eraseOffset) - 1;
                uint32_t moreToErase = eraseIndex + 1;
                while ((moreToErase << 6) < outputOffset + counter) {
                    output[moreToErase++] = 0;
                }
            }
        }

    }
}