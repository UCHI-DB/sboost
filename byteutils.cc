//
// Created by harper on 8/18/19.
//

#include <cstdlib>
#include "byteutils.h"

namespace sboost {
    namespace byteutils {
        uint64_t spanTo64(uint8_t bitwidth, uint32_t value) {
            uint64_t mask = (1L << bitwidth) - 1;
            uint64_t base = value & mask;
            uint64_t result = base;
            uint32_t round = 64 / bitwidth;
            uint32_t i = 1;
            while (i <= (round >> 1)) {
                result = result | (result << (i * bitwidth));
                i *= 2;
            }
            for (; i < round; i++) {
                result |= base << (i * bitwidth);
            }
            return result;
        }

        void bitpack(uint32_t *values, uint64_t entryCount, uint32_t bitwidth, uint8_t *output) {
//            uint32_t mask = (1 << bitwidth) - 1;

//            uint64_t bitsize = bitwidth * entryCount;
//            uint64_t rescount = (bitsize >> 3) + ((bitsize & 7) ? 1 : 0);
            uint64_t *res = (uint64_t *) output;

            uint32_t resindex = 0;
            uint32_t resoffset = 0;

            for (uint64_t i = 0; i < entryCount; i++) {
                res[resindex] |= ((uint64_t) values[i]) << resoffset;
                resoffset += bitwidth;
                if (resoffset >= 64) {
                    resindex += 1;
                    resoffset &= 0x3F;
                    res[resindex] |= ((uint64_t) values[i]) >> (bitwidth - resoffset);
                }
            }
        }

        uint32_t readIntLittleEndian(const uint8_t *input, uint32_t *offset) {
            uint32_t result = ((uint32_t *) input)[*offset];
            *offset += 4;
            return result;
        }

        uint32_t readIntLittleEndianPaddedOnBitWidth(const uint8_t *input, uint32_t *offset, uint8_t bitWidth) {
            uint8_t byteWidth = (bitWidth + 7) >> 3;
            uint32_t result;
            switch (byteWidth) {
                case 1:
                    result = input[*offset];
                    (*offset)++;
                    break;
                case 2:
                    result = ((uint16_t *) input)[*offset];
                    *offset += 2;
                    break;
                case 3:
                    result = ((uint32_t *) input)[*offset] & 0xFFFFFF;
                    *offset += 3;
                    break;
                case 4:
                    result = ((uint32_t *) input)[*offset];
                    *offset += 4;
                    break;
                default:
                    return 0;
            }
            return result;
        }

        uint32_t readUnsignedVarInt(const uint8_t *input, uint32_t *offset) {
            uint32_t value = 0;
            uint32_t i = 0;
            uint32_t b;
            while (((b = input[(*offset)++]) & 0x80) != 0) {
                value |= (b & 0x7F) << i;
                i += 7;
            }
            return value | (b << i);
        }

        uint64_t readUnsignedVarLong(const uint8_t *input, uint32_t *offset) {
            uint64_t value = 0;
            uint32_t i = 0;
            uint32_t b;
            while (((b = input[(*offset)++]) & 0x80) != 0) {
                value |= (b & 0x7F) << i;
                i += 7;
            }
            return value | (b << i);
        }

        int32_t readZigZagVarInt(const uint8_t *input, uint32_t *offset) {
            uint32_t raw = readUnsignedVarInt(input, offset);
            int32_t result;
            *reinterpret_cast<uint32_t *>(&result) = (raw >> 1) ^ -(static_cast<int64_t>(raw & 1));
            return result;
        }

        int64_t readZigZagVarLong(const uint8_t *input, uint32_t *offset) {
            uint64_t raw = readUnsignedVarLong(input, offset);
            return (int64_t)((raw >> 1) ^ -(static_cast<int64_t>(raw & 1)));
        }

    }
}