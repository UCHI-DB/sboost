//
// Created by harper on 10/21/19.
//

#ifndef SBOOST_ENCODING_ENCODINGUTILS_H
#define SBOOST_ENCODING_ENCODINGUTILS_H

#include <cstdint>

namespace sboost {
    namespace encoding {
        /**
         * Clean up the bitmap that is overflown
         *
         * @param counter
         * @param numEntry
         * @param output
         * @param outputOffset
         */
        void cleanup(uint32_t counter, uint32_t numEntry, uint64_t *output, uint32_t outputOffset);
    }
}
#endif //SBOOST_ENCODING_ENCODINGUTILS_H
