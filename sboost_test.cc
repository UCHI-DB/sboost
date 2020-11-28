//
// Created by harper on 8/18/19.
//

#include <gtest/gtest.h>
#include "byteutils.h"
#include "sboost.h"

using namespace sboost;

void prepareData(uint8_t *);

TEST(SBoost, Equal) {
    uint8_t bitpacked2[192];
    prepareData(bitpacked2);

    uint64_t result2_exp[8] = {
            0x218012640444A10, 0xA20400042020005A, 0x24000184149010F, 0x8448308000120002,
            0x3108154CA2000204, 0x80405C0088444832, 0x490043A00404246C, 0x24000201206016
    };
    uint64_t result2[8] = {0};

    sboost::Bitpack sBoost256(3, 3);

    sBoost256.equal(bitpacked2, 504, result2, 0);

    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(result2[i], result2_exp[i]) << i;
    }
}

TEST(SBoost, Equal256SmallWidth) {
    uint32_t input[] = {1, 1, 2, 3, 1, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2,
                        1, 1, 2, 3, 1, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2,
                        1, 1, 2, 3, 1, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2,
                        1, 1, 2, 3, 1, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2,
                        1, 1, 2, 3, 1, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2,
                        1, 1, 2, 3, 1, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2
    };
    uint8_t bitpacked[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    byteutils::bitpack(input, 96, 2, bitpacked);

    sboost::Bitpack sBoost(2, 1);

    uint64_t result[] = {0, 0};
    sBoost.equal(bitpacked, 96, result, 0);

    EXPECT_EQ(result[0], 0x34d334d334d334D3);
    EXPECT_EQ(result[1], 0x34d334D3);
}

TEST(SBoost, Less256) {
    uint32_t input[] = {13, 22, 1, 9, 25, 17, 6, 22, 12, 31, 12, 21, 0, 5};
    uint8_t bitpacked[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    byteutils::bitpack(input, 14, 5, bitpacked);

    sboost::Bitpack sBoost(5, 22);

    uint64_t result[] = {0};
    sBoost.less(bitpacked, 14, result, 0);

    EXPECT_EQ(result[0], 0x3D6D);

}

TEST(SBoost, Greater256) {
    uint32_t input[] = {13, 22, 1, 9, 25, 17, 6, 22, 12, 31, 12, 21, 0, 5};
    uint8_t bitpacked[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    byteutils::bitpack(input, 14, 5, bitpacked);

    sboost::Bitpack sBoost(5, 22);

    uint64_t result[] = {0};
    sBoost.greater(bitpacked, 14, result, 0);

    EXPECT_EQ(result[0], 0x210);
}


TEST(SBoost, RangeLe256) {
    uint32_t input[] = {13, 22, 1, 9, 25, 17, 6, 22, 12, 31, 12, 21, 0, 5};
    uint8_t bitpacked[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    byteutils::bitpack(input, 14, 5, bitpacked);

    sboost::Bitpack sBoost(5, 17, 23);

    uint64_t result[] = {0};
    sBoost.rangele(bitpacked, 14, result, 0);

    EXPECT_EQ(result[0], 0x8A2);
}

TEST(SBoost, Between256) {
    uint32_t input[] = {13, 22, 1, 9, 25, 17, 6, 22, 12, 31, 12, 21, 0, 5};
    uint8_t bitpacked[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    byteutils::bitpack(input, 14, 5, bitpacked);

    sboost::Bitpack sBoost(5, 17, 22);

    uint64_t result[] = {0};
    sBoost.between(bitpacked, 14, result, 0);

    EXPECT_EQ(result[0], 0x8A2);
}


TEST(SBoost, Equal512) {
    uint8_t bitpacked2[192];
    prepareData(bitpacked2);

    uint64_t result2_exp[8] = {
            0x218012640444A10, 0xA20400042020005A, 0x24000184149010F, 0x8448308000120002,
            0x3108154CA2000204, 0x80405C0088444832, 0x490043A00404246C, 0x24000201206016
    };
    uint64_t result2[8] = {0};
    sboost::Bitpack sBoost512(3, 3);
    sBoost512.equal(bitpacked2, 504, result2, 0);

    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(result2[i], result2_exp[i]) << i;
    }
}

TEST(BitpackCompareTest, Less) {
    uint32_t input1[] = {13, 22, 1, 9, 25, 17, 6, 22, 12, 31, 12, 21, 0, 5};
    uint8_t bitpacked1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    byteutils::bitpack(input1, 14, 5, bitpacked1);

    uint32_t input2[] = {30, 10, 9, 29, 5, 17, 8, 2, 2, 8, 22, 10, 0, 9};
    uint8_t bitpacked2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    byteutils::bitpack(input2, 14, 5, bitpacked2);

    uint64_t result[] = {0, 0};

    BitpackCompare compare(5);
    compare.less(bitpacked1, bitpacked2, 14, result, 0);

    EXPECT_EQ(0x244d, /* 10 0100 0100 1101*/  result[0]);
}

TEST(SDelta, Cumsum) {
//    int32_t values[8] = {32432, 42442, 529532, 13442, 2525232, 3143243, 423432, 23232};
    int32_t values[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    __m256i holder = _mm256_setr_epi32(values[0], values[1], values[2], values[3],
                                       values[4], values[5], values[6], values[7]);
    __m256i cs = cumsum32(holder);

    for (int i = 1; i < 8; ++i) {
        values[i] += values[i - 1];
    }

    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(values[i], (cs[i / 2] >> (i % 2) * 32) & 0xFFFFFFFF);
    }
}

void prepareData(uint8_t *bitpacked) {
    bitpacked[0] = 0x48;
    bitpacked[1] = 0xB4;
    bitpacked[2] = 0x4;
    bitpacked[3] = 0x1C;
    bitpacked[4] = 0x6;
    bitpacked[5] = 0x8E;
    bitpacked[6] = 0xC1;
    bitpacked[7] = 0x28;
    bitpacked[8] = 0x4D;
    bitpacked[9] = 0xC;
    bitpacked[10] = 0x48;
    bitpacked[11] = 0xC;
    bitpacked[12] = 0xD9;
    bitpacked[13] = 0xC0;
    bitpacked[14] = 0x5;
    bitpacked[15] = 0x83;
    bitpacked[16] = 0x92;
    bitpacked[17] = 0x0;
    bitpacked[18] = 0x14;
    bitpacked[19] = 0xB7;
    bitpacked[20] = 0x88;
    bitpacked[21] = 0x99;
    bitpacked[22] = 0x44;
    bitpacked[23] = 0x5;
    bitpacked[24] = 0x99;
    bitpacked[25] = 0x36;
    bitpacked[26] = 0x8E;
    bitpacked[27] = 0x50;
    bitpacked[28] = 0x8;
    bitpacked[29] = 0x8A;
    bitpacked[30] = 0x8;
    bitpacked[31] = 0xC8;
    bitpacked[32] = 0x31;
    bitpacked[33] = 0x44;
    bitpacked[34] = 0xA4;
    bitpacked[35] = 0x29;
    bitpacked[36] = 0xC1;
    bitpacked[37] = 0x28;
    bitpacked[38] = 0x80;
    bitpacked[39] = 0x52;
    bitpacked[40] = 0x80;
    bitpacked[41] = 0x88;
    bitpacked[42] = 0xE0;
    bitpacked[43] = 0xC0;
    bitpacked[44] = 0x50;
    bitpacked[45] = 0x18;
    bitpacked[46] = 0xC2;
    bitpacked[47] = 0x69;
    bitpacked[48] = 0xDB;
    bitpacked[49] = 0x16;
    bitpacked[50] = 0x90;
    bitpacked[51] = 0x93;
    bitpacked[52] = 0xC4;
    bitpacked[53] = 0x48;
    bitpacked[54] = 0x63;
    bitpacked[55] = 0x16;
    bitpacked[56] = 0xD;
    bitpacked[57] = 0x63;
    bitpacked[58] = 0x82;
    bitpacked[59] = 0x4C;
    bitpacked[60] = 0x12;
    bitpacked[61] = 0x37;
    bitpacked[62] = 0x86;
    bitpacked[63] = 0x84;
    bitpacked[64] = 0x4;
    bitpacked[65] = 0x92;
    bitpacked[66] = 0xA0;
    bitpacked[67] = 0xC8;
    bitpacked[68] = 0x2C;
    bitpacked[69] = 0x18;
    bitpacked[70] = 0xA1;
    bitpacked[71] = 0x40;
    bitpacked[72] = 0x5A;
    bitpacked[73] = 0x98;
    bitpacked[74] = 0x10;
    bitpacked[75] = 0x8A;
    bitpacked[76] = 0x80;
    bitpacked[77] = 0x44;
    bitpacked[78] = 0x1C;
    bitpacked[79] = 0x30;
    bitpacked[80] = 0x91;
    bitpacked[81] = 0x51;
    bitpacked[82] = 0x0;
    bitpacked[83] = 0x0;
    bitpacked[84] = 0x89;
    bitpacked[85] = 0x8;
    bitpacked[86] = 0x61;
    bitpacked[87] = 0x4C;
    bitpacked[88] = 0xB2;
    bitpacked[89] = 0x51;
    bitpacked[90] = 0x51;
    bitpacked[91] = 0xA6;
    bitpacked[92] = 0x8C;
    bitpacked[93] = 0xE2;
    bitpacked[94] = 0x18;
    bitpacked[95] = 0x61;
    bitpacked[96] = 0xD1;
    bitpacked[97] = 0x94;
    bitpacked[98] = 0x50;
    bitpacked[99] = 0x5A;
    bitpacked[100] = 0xA4;
    bitpacked[101] = 0x48;
    bitpacked[102] = 0x64;
    bitpacked[103] = 0x2;
    bitpacked[104] = 0x4;
    bitpacked[105] = 0x58;
    bitpacked[106] = 0xC2;
    bitpacked[107] = 0x69;
    bitpacked[108] = 0xD1;
    bitpacked[109] = 0x26;
    bitpacked[110] = 0xC;
    bitpacked[111] = 0xC3;
    bitpacked[112] = 0x32;
    bitpacked[113] = 0x45;
    bitpacked[114] = 0xC;
    bitpacked[115] = 0x47;
    bitpacked[116] = 0x26;
    bitpacked[117] = 0x13;
    bitpacked[118] = 0xB5;
    bitpacked[119] = 0x51;
    bitpacked[120] = 0x5C;
    bitpacked[121] = 0xB8;
    bitpacked[122] = 0x9;
    bitpacked[123] = 0x50;
    bitpacked[124] = 0x16;
    bitpacked[125] = 0x2C;
    bitpacked[126] = 0xE2;
    bitpacked[127] = 0xC0;
    bitpacked[128] = 0x8C;
    bitpacked[129] = 0x21;
    bitpacked[130] = 0x6;
    bitpacked[131] = 0x64;
    bitpacked[132] = 0x0;
    bitpacked[133] = 0x19;
    bitpacked[134] = 0x91;
    bitpacked[135] = 0xC8;
    bitpacked[136] = 0x36;
    bitpacked[137] = 0x4D;
    bitpacked[138] = 0x64;
    bitpacked[139] = 0xA4;
    bitpacked[140] = 0x2C;
    bitpacked[141] = 0x42;
    bitpacked[142] = 0x80;
    bitpacked[143] = 0x68;
    bitpacked[144] = 0xC1;
    bitpacked[145] = 0x96;
    bitpacked[146] = 0xD;
    bitpacked[147] = 0xD4;
    bitpacked[148] = 0xC0;
    bitpacked[149] = 0x1;
    bitpacked[150] = 0xC8;
    bitpacked[151] = 0x20;
    bitpacked[152] = 0xA;
    bitpacked[153] = 0xC4;
    bitpacked[154] = 0xC0;
    bitpacked[155] = 0x50;
    bitpacked[156] = 0x20;
    bitpacked[157] = 0xC0;
    bitpacked[158] = 0x61;
    bitpacked[159] = 0x9B;
    bitpacked[160] = 0x40;
    bitpacked[161] = 0xC;
    bitpacked[162] = 0x94;
    bitpacked[163] = 0x18;
    bitpacked[164] = 0x41;
    bitpacked[165] = 0x23;
    bitpacked[166] = 0x47;
    bitpacked[167] = 0xE;
    bitpacked[168] = 0xDA;
    bitpacked[169] = 0xB0;
    bitpacked[170] = 0x80;
    bitpacked[171] = 0x84;
    bitpacked[172] = 0x98;
    bitpacked[173] = 0x2D;
    bitpacked[174] = 0x94;
    bitpacked[175] = 0x88;
    bitpacked[176] = 0x51;
    bitpacked[177] = 0x13;
    bitpacked[178] = 0x10;
    bitpacked[179] = 0x84;
    bitpacked[180] = 0x9C;
    bitpacked[181] = 0xA0;
    bitpacked[182] = 0x24;
    bitpacked[183] = 0x61;
    bitpacked[184] = 0x22;
    bitpacked[185] = 0x42;
    bitpacked[186] = 0xC0;
    bitpacked[187] = 0xC2;
    bitpacked[188] = 0x89;
    bitpacked[189] = 0;
    bitpacked[190] = 0;
    bitpacked[191] = 0;
}
