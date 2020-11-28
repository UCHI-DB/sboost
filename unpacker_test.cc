//
// Created by harper on 3/15/18.
//

#include <gtest/gtest.h>
#include "byteutils.h"
#include "unpacker.h"

using namespace sboost;


int extract_entry(int *input, int index, int offset, int entrySize) {
    int mask = (1 << entrySize) - 1;
    int word0 = *(input + index);
    if (offset + entrySize <= 32) {
        return (word0 >> offset) & mask;
    } else {
        int mask0 = (1 << (32 - offset)) - 1;
        int word1 = *(input + index + 1);
        return ((word0 >> offset & mask0) | word1 << (32 - offset)) & mask;
    }
}

TEST(Small32Unpacker, unpack) {
    int entrySize = 21;
    int entryCount = 17;
    uint32_t data[17] = {20124, 8831, 2575, 1977, 15, 42441, 302690, 871222, 323452, 424532, 29434,
                         939141, 4244, 324314, 13, 1, 874255};
    uint8_t output[64]{0};
    byteutils::bitpack(data, entryCount, entrySize, output);

    Small32Unpacker unpacker(entrySize);


    for (int o = 0; o < entryCount; o += 8) {
        __m256i unpacked = unpacker.unpack(output + entrySize * (o >> 3));

        for (int i = 0; i < 8; i++) {
            int bitoff = (o + i) * entrySize;
            int extract = extract_entry((int *) output, bitoff / 32, bitoff % 32, entrySize);
            EXPECT_EQ(extract, (unpacked[i / 2] >> (i % 2) * 32) & 0xFFFFFFFF) << o << "," << i;
        }
    }
}

TEST(Small32Unpacker, unpackSmall) {
    int entrySize = 14;
    int entryCount = 17;
    uint32_t data[17] = {2124, 831, 2575, 1977, 15, 4241, 3090, 822, 3252, 4245, 934,
                         941, 4244, 3314, 13, 1, 874};
    uint8_t output[64]{0};
    byteutils::bitpack(data, 17, entrySize, output);

    Small32Unpacker unpacker(entrySize);


    for (int o = 0; o < entryCount; o += 8) {
        __m256i unpacked = unpacker.unpack(output + entrySize * (o >> 3));

        for (int i = 0; i < 8; i++) {
            int bitoff = (o + i) * entrySize;
            int extract = extract_entry((int *) output, bitoff / 32, bitoff % 32, entrySize);
            EXPECT_EQ(extract, (unpacked[i / 2] >> (i % 2) * 32) & 0xFFFFFFFF) << o << "," << i;
        }
    }
}


TEST(Large32Unpacker, unpack) {
    int entrySize = 30;
    int entryCount = 17;
    uint32_t data[17] = {82934, 1941331, 224875, 4201277, 304135, 224241, 26, 112192, 99552, 4234532,
                         990342, 32342411, 42349022, 42431414, 324231342, 32324414, 32767};
    uint8_t output[64]{0};
    byteutils::bitpack(data, 17, entrySize, output);

    Large32Unpacker unpacker(entrySize);


    for (int o = 0; o < entryCount; o += 8) {
        __m256i unpacked = unpacker.unpack(output + entrySize * (o >> 3));

        for (int i = 0; i < 8; i++) {
            int bitoff = (o + i) * entrySize;
            int extract = extract_entry((int *) output, bitoff / 32, bitoff % 32, entrySize);
            EXPECT_EQ(extract, (unpacked[i / 2] >> (i % 2) * 32) & 0xFFFFFFFF) << o << "," << i;
        }
    }
}

TEST(Unpacker, unpack) {
    std::array<uint32_t, 10007> buffer;
    uint32_t size= 10007;
    uint8_t *bytebuffer = (uint8_t *) malloc(sizeof(uint8_t) * 4 * size);
    uint32_t *outputbuffer = (uint32_t *) malloc(sizeof(uint32_t) * size);
    srand(1024);
    for (int es = 2; es <= 31; ++es) {
        memset(bytebuffer, 0, sizeof(uint8_t) * 4 * size);
        uint32_t mask = (1u << es) - 1;
        for (uint32_t j = 0; j < size; ++j) {
            buffer[j] = mask & static_cast<uint32_t>(rand() & 0xFF);
        }
        sboost::byteutils::bitpack(buffer.data(), size, es, bytebuffer);

        sboost::unpacks[es](bytebuffer, size, outputbuffer);
        for (uint32_t j = 0; j < size; ++j) {
            EXPECT_EQ(buffer[j], outputbuffer[j]) << es << "," << j;
        }
    }

}

