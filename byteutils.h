//
// Created by harper on 8/18/19.
//

#ifndef SBOOST_BYTESUTILS_H
#define SBOOST_BYTESUTILS_H

#include <cstdint>

namespace sboost {
    namespace byteutils {
        uint64_t spanTo64(uint8_t bitwidth, uint32_t value);

        void bitpack(uint32_t *values, uint64_t entryCount, uint32_t bitwidth, uint8_t *output);

        uint32_t readIntLittleEndian(const uint8_t *input, uint32_t *);

        uint32_t readUnsignedVarInt(const uint8_t *input, uint32_t *);

        uint64_t readUnsignedVarLong(const uint8_t *input, uint32_t *);

        uint32_t readIntLittleEndianPaddedOnBitWidth(const uint8_t *input, uint32_t *, uint8_t);

        int32_t readZigZagVarInt(const uint8_t *input, uint32_t *offset);

        int64_t readZigZagVarLong(const uint8_t *input, uint32_t *offset);
    }

}
#endif //SBOOST_BYTESUTILS_H
