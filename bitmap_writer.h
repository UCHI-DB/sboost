//
// Created by harper on 9/14/19.
//

#ifndef SBOOST_BITMAP_H
#define SBOOST_BITMAP_H

#include <cstdint>

namespace sboost {
    class BitmapWriter {
    protected:
        uint64_t *data;
        uint32_t index;
        uint32_t bitOffset;
    public:
        BitmapWriter(uint64_t *data, uint32_t offset);

        void appendWord(uint64_t *word, uint32_t count);

        void appendBits(uint8_t bit, uint32_t rep);

        void appendByte(uint8_t byte);

        inline uint64_t *base() {
            return data;
        }

        inline uint32_t offset() {
            return (index << 6) + bitOffset;
        }

        void moveForward(uint32_t count);
    };
}

#endif //SBOOST_BITMAP_H
