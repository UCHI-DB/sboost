//
// Created by harper on 9/14/19.
//
#include "bitmap_writer.h"
#include <cstring>

namespace sboost {
    BitmapWriter::BitmapWriter(uint64_t *data, uint32_t offset) {
        this->data = data;
        this->index = offset >> 6;
        this->bitOffset = offset & 0x3F;
    }

    void BitmapWriter::appendBits(uint8_t bit, uint32_t repetition) {
        if (bit != 0) {
            // We simply assume this is an empty bitmap, and do not put zero inside
            if (repetition + bitOffset < 64) {
                data[index] |= ((1L << repetition) - 1) << bitOffset;
            } else {
                uint32_t remain = repetition;
                data[index++] |= -1L << bitOffset;
                remain -= 64 - bitOffset;
                while (remain >= 64) {
                    data[index++] = -1L;
                    remain -= 64;
                }
                if (remain > 0) {
                    data[index] = (1L << remain) - 1;
                }
            }
        } else {
            index += (bitOffset + repetition) >> 6;
        }
        bitOffset = (bitOffset + repetition) & 0x3F;
    }

    void BitmapWriter::appendWord(uint64_t *word, uint32_t count) {
        uint32_t remain = count;
        if (bitOffset == 0) {
//            while (remain >= 64) {
//                data[index++] = word[destIndex++];
//                remain -= 64;
//            }
            int destIndex = remain >> 6;
            memcpy((void *) (data + index), (void *) word, sizeof(uint64_t) * destIndex);
            index += destIndex;
            remain &= 0x3F;
            if (remain > 0) {
                data[index] = word[destIndex] & ((1L << remain) - 1);
            }
        } else {
            int destIndex = 0;
            while (remain >= 64) {
                data[index] |= word[destIndex] << bitOffset;
                data[++index] = word[destIndex++] >> (64 - bitOffset);
                remain -= 64;
            }
            if (remain > 0) {
                auto mask = (1L << remain) - 1;
                auto masked = word[destIndex] & mask;
                if (remain < 64 - bitOffset) {
                    data[index] |= masked << bitOffset;
                } else if (remain == 64 - bitOffset) {
                    data[index++] |= masked << bitOffset;
                } else {
                    data[index++] |= masked << bitOffset;
                    data[index] = masked >> (64 - bitOffset);
                }
            }
        }
        bitOffset = (bitOffset + count) & 0x3F;
    }

    void BitmapWriter::appendByte(uint8_t byte) {
        uint64_t value = byte;

        data[index] |= value << bitOffset;
        bitOffset += 8;
        if (bitOffset >= 64) {
            data[++index] = value >> (72 - bitOffset);
            bitOffset -= 64;
        }
    }

    void BitmapWriter::moveForward(uint32_t count) {
        bitOffset += count;
        index += bitOffset >> 6;
        bitOffset &= 0x3f;
    }

}