//
// Created by harper on 9/14/19.
//
#include <gtest/gtest.h>
#include "bitmap_writer.h"

using namespace sboost;

TEST(Bitmap, appendWord) {
    uint64_t content[100] = {0};
    BitmapWriter bitmap(content, 137);

    uint64_t another[5] = {0x3f323daeeb004231, 0x33214, 0x4243234, 0x42342343, 38429};

    bitmap.appendWord(another, 100);

    for (int i = 0; i < 100; i++) {
        int idxa = (i + 137) >> 6;
        int offa = (i + 137) & 0x3f;
        int idxb = i >> 6;
        int offb = i & 0x3f;

        EXPECT_EQ((content[idxa] >> offa) & 1, (another[idxb] >> offb) & 1) << i;
    }
    for (int i = 100; i < 128; i++) {
        int idxa = (i + 137) >> 6;
        int offa = (i + 137) & 0x3f;

        EXPECT_EQ((content[idxa] >> offa) & 1, 0) << i;
    }
}

TEST(Bitmap, appendWordZeroOffset) {
    uint64_t content[100] = {0};
    BitmapWriter bitmap(content, 0);

    uint64_t another[5] = {0x3f323daeeb004231, 0x3424ff1220183214, 0x4200325411013234, 0x423133134234dd23,
                           0x3134143138420009};

    bitmap.appendWord(another, 179);

    for (int i = 0; i < 179; i++) {
        int idxa = (i) >> 6;
        int offa = (i) & 0x3f;
        EXPECT_EQ((content[idxa] >> offa) & 1, (another[idxa] >> offa) & 1) << i;
    }
}


TEST(Bitmap, appendBits) {
    uint64_t content[100] = {0};
    BitmapWriter bitmap(content, 139);

    bitmap.appendBits(1, 415);

    for (int i = 0; i < 415; i++) {
        int idxa = (i + 139) >> 6;
        int offa = (i + 139) & 0x3f;

        EXPECT_EQ((content[idxa] >> offa) & 1, 1) << i;
    }
}

TEST(Bitmap, appendByte) {
    uint64_t content[100] = {0};
    BitmapWriter bitmap(content, 1);

    bitmap.appendByte(0x42);
    bitmap.appendByte(0x37);
    bitmap.appendByte(0x51);
    bitmap.appendByte(0x85);
    bitmap.appendByte(0x21);
    bitmap.appendByte(0x13);
    bitmap.appendByte(0xaa);
    bitmap.appendByte(0x4c);

    uint64_t num = 0x4caa132185513742;
    ASSERT_EQ(num << 1, content[0]);
    ASSERT_EQ(num >> 63, content[1]);
}