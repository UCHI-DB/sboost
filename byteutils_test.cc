//
// Created by harper on 8/18/19.
//


#include <gtest/gtest.h>
#include <stdlib.h>
#include "byteutils.h"

using namespace sboost;

TEST(BytesUtils, spanTo64) {
    int bitwidth = 9;  // 0x16
    uint64_t res = byteutils::spanTo64(bitwidth, 22);

    // 7 copies
    EXPECT_EQ(res, 22L | (22L << 9) | (22L << 18) | (22L << 27) | (22L << 36) | (22L << 45) | (22L << 54));

//    for (int i = 2; i < 32; i++) {
//        uint32_t value = 1 << (i - 1);
//        printf("0x%llXL,", common::spanTo64(i, value));
//    }
}

TEST(BytesUtils, bitpack) {
    uint32_t input[] = {13, 22, 1, 9, 25, 17, 6, 22, 12, 31, 12, 21, 0, 5};

    uint8_t result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    byteutils::bitpack(input, 14, 5, result);

    uint8_t expected[] = {0xCD, 0x86, 0x94, 0xA3, 0xB1, 0xEC, 0xB3, 0x0A, 0x0A};

    for (int i = 0; i < 9; i++) {
        EXPECT_EQ(expected[i], result[i]);
    }
}

TEST(BytesUtils, readZigzag) {
    uint8_t data[] = {187, 37, 0};
    uint32_t offset = 0;
    int64_t zigzag = byteutils::readZigZagVarLong(data, &offset);
    ASSERT_EQ(-2398, zigzag);

}
