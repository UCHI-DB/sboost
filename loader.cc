//
// Created by Hao Jiang on 12/1/20.
//
#include "loader.h"

namespace sboost {
    namespace loader {

        void load1(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 8))[0];
            buffer[2] = ((uint64_t *) (data + 16))[0];
            buffer[3] = ((uint64_t *) (data + 24))[0];
            buffer[4] = ((uint64_t *) (data + 32))[0];
            buffer[5] = ((uint64_t *) (data + 40))[0];
            buffer[6] = ((uint64_t *) (data + 48))[0];
            buffer[7] = ((uint64_t *) (data + 56))[0];
        }

        void load2(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 8))[0];
            buffer[2] = ((uint64_t *) (data + 16))[0];
            buffer[3] = ((uint64_t *) (data + 24))[0];
            buffer[4] = ((uint64_t *) (data + 32))[0];
            buffer[5] = ((uint64_t *) (data + 40))[0];
            buffer[6] = ((uint64_t *) (data + 48))[0];
            buffer[7] = ((uint64_t *) (data + 56))[0];
        }

        void load3(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 7;
            buffer[2] = ((uint64_t *) (data + 15))[0];
            buffer[3] = ((uint64_t *) (data + 22))[0] >> 7;
            buffer[4] = ((uint64_t *) (data + 30))[0];
            buffer[5] = ((uint64_t *) (data + 37))[0] >> 7;
            buffer[6] = ((uint64_t *) (data + 45))[0];
            buffer[7] = ((uint64_t *) (data + 52))[0] >> 7;
        }

        void load4(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 8))[0];
            buffer[2] = ((uint64_t *) (data + 16))[0];
            buffer[3] = ((uint64_t *) (data + 24))[0];
            buffer[4] = ((uint64_t *) (data + 32))[0];
            buffer[5] = ((uint64_t *) (data + 40))[0];
            buffer[6] = ((uint64_t *) (data + 48))[0];
            buffer[7] = ((uint64_t *) (data + 56))[0];
        }

        void load5(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 15))[0];
            buffer[3] = ((uint64_t *) (data + 22))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 30))[0];
            buffer[5] = ((uint64_t *) (data + 37))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 45))[0];
            buffer[7] = ((uint64_t *) (data + 52))[0] >> 4;
        }

        void load6(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 15))[0];
            buffer[3] = ((uint64_t *) (data + 22))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 30))[0];
            buffer[5] = ((uint64_t *) (data + 37))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 45))[0];
            buffer[7] = ((uint64_t *) (data + 52))[0] >> 4;
        }

        void load7(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 7;
            buffer[2] = ((uint64_t *) (data + 14))[0] >> 7;
            buffer[3] = ((uint64_t *) (data + 21))[0] >> 7;
            buffer[4] = ((uint64_t *) (data + 28))[0] >> 7;
            buffer[5] = ((uint64_t *) (data + 35))[0] >> 7;
            buffer[6] = ((uint64_t *) (data + 42))[0] >> 7;
            buffer[7] = ((uint64_t *) (data + 49))[0] >> 7;
        }

        void load8(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 8))[0];
            buffer[2] = ((uint64_t *) (data + 16))[0];
            buffer[3] = ((uint64_t *) (data + 24))[0];
            buffer[4] = ((uint64_t *) (data + 32))[0];
            buffer[5] = ((uint64_t *) (data + 40))[0];
            buffer[6] = ((uint64_t *) (data + 48))[0];
            buffer[7] = ((uint64_t *) (data + 56))[0];
        }

        void load9(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 7;
            buffer[2] = ((uint64_t *) (data + 14))[0] >> 5;
            buffer[3] = ((uint64_t *) (data + 21))[0] >> 3;
            buffer[4] = ((uint64_t *) (data + 28))[0] >> 1;
            buffer[5] = ((uint64_t *) (data + 36))[0];
            buffer[6] = ((uint64_t *) (data + 43))[0] >> 7;
            buffer[7] = ((uint64_t *) (data + 50))[0] >> 5;
        }

        void load10(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 15))[0];
            buffer[3] = ((uint64_t *) (data + 22))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 30))[0];
            buffer[5] = ((uint64_t *) (data + 37))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 45))[0];
            buffer[7] = ((uint64_t *) (data + 52))[0] >> 4;
        }

        void load11(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 6))[0] >> 7;
            buffer[2] = ((uint64_t *) (data + 13))[0] >> 6;
            buffer[3] = ((uint64_t *) (data + 20))[0] >> 5;
            buffer[4] = ((uint64_t *) (data + 27))[0] >> 4;
            buffer[5] = ((uint64_t *) (data + 34))[0] >> 3;
            buffer[6] = ((uint64_t *) (data + 41))[0] >> 2;
            buffer[7] = ((uint64_t *) (data + 48))[0] >> 1;
        }

        void load12(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 15))[0];
            buffer[3] = ((uint64_t *) (data + 22))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 30))[0];
            buffer[5] = ((uint64_t *) (data + 37))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 45))[0];
            buffer[7] = ((uint64_t *) (data + 52))[0] >> 4;
        }

        void load13(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 6))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 13))[0];
            buffer[3] = ((uint64_t *) (data + 19))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 26))[0];
            buffer[5] = ((uint64_t *) (data + 32))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 39))[0];
            buffer[7] = ((uint64_t *) (data + 45))[0] >> 4;
        }

        void load14(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0];
            buffer[2] = ((uint64_t *) (data + 14))[0];
            buffer[3] = ((uint64_t *) (data + 21))[0];
            buffer[4] = ((uint64_t *) (data + 28))[0];
            buffer[5] = ((uint64_t *) (data + 35))[0];
            buffer[6] = ((uint64_t *) (data + 42))[0];
            buffer[7] = ((uint64_t *) (data + 49))[0];
        }

        void load15(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 15))[0];
            buffer[3] = ((uint64_t *) (data + 22))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 30))[0];
            buffer[5] = ((uint64_t *) (data + 37))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 45))[0];
            buffer[7] = ((uint64_t *) (data + 52))[0] >> 4;
        }

        void load16(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 8))[0];
            buffer[2] = ((uint64_t *) (data + 16))[0];
            buffer[3] = ((uint64_t *) (data + 24))[0];
            buffer[4] = ((uint64_t *) (data + 32))[0];
            buffer[5] = ((uint64_t *) (data + 40))[0];
            buffer[6] = ((uint64_t *) (data + 48))[0];
            buffer[7] = ((uint64_t *) (data + 56))[0];
        }

        void load17(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 6))[0] >> 3;
            buffer[2] = ((uint64_t *) (data + 12))[0] >> 6;
            buffer[3] = ((uint64_t *) (data + 19))[0] >> 1;
            buffer[4] = ((uint64_t *) (data + 25))[0] >> 4;
            buffer[5] = ((uint64_t *) (data + 31))[0] >> 7;
            buffer[6] = ((uint64_t *) (data + 38))[0] >> 2;
            buffer[7] = ((uint64_t *) (data + 44))[0] >> 5;
        }

        void load18(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 6))[0] >> 6;
            buffer[2] = ((uint64_t *) (data + 13))[0] >> 4;
            buffer[3] = ((uint64_t *) (data + 20))[0] >> 2;
            buffer[4] = ((uint64_t *) (data + 27))[0];
            buffer[5] = ((uint64_t *) (data + 33))[0] >> 6;
            buffer[6] = ((uint64_t *) (data + 40))[0] >> 4;
            buffer[7] = ((uint64_t *) (data + 47))[0] >> 2;
        }

        void load19(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 1;
            buffer[2] = ((uint64_t *) (data + 14))[0] >> 2;
            buffer[3] = ((uint64_t *) (data + 21))[0] >> 3;
            buffer[4] = ((uint64_t *) (data + 28))[0] >> 4;
            buffer[5] = ((uint64_t *) (data + 35))[0] >> 5;
            buffer[6] = ((uint64_t *) (data + 42))[0] >> 6;
            buffer[7] = ((uint64_t *) (data + 49))[0] >> 7;
        }

        void load20(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 15))[0];
            buffer[3] = ((uint64_t *) (data + 22))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 30))[0];
            buffer[5] = ((uint64_t *) (data + 37))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 45))[0];
            buffer[7] = ((uint64_t *) (data + 52))[0] >> 4;
        }

        void load21(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 7;
            buffer[2] = ((uint64_t *) (data + 13))[0] >> 1;
            buffer[3] = ((uint64_t *) (data + 21))[0];
            buffer[4] = ((uint64_t *) (data + 28))[0] >> 7;
            buffer[5] = ((uint64_t *) (data + 34))[0] >> 1;
            buffer[6] = ((uint64_t *) (data + 42))[0];
            buffer[7] = ((uint64_t *) (data + 49))[0] >> 7;
        }

        void load22(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 5))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 11))[0];
            buffer[3] = ((uint64_t *) (data + 16))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 22))[0];
            buffer[5] = ((uint64_t *) (data + 27))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 33))[0];
            buffer[7] = ((uint64_t *) (data + 38))[0] >> 4;
        }

        void load23(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 5))[0] >> 6;
            buffer[2] = ((uint64_t *) (data + 11))[0] >> 4;
            buffer[3] = ((uint64_t *) (data + 17))[0] >> 2;
            buffer[4] = ((uint64_t *) (data + 23))[0];
            buffer[5] = ((uint64_t *) (data + 28))[0] >> 6;
            buffer[6] = ((uint64_t *) (data + 34))[0] >> 4;
            buffer[7] = ((uint64_t *) (data + 40))[0] >> 2;
        }

        void load24(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 6))[0];
            buffer[2] = ((uint64_t *) (data + 12))[0];
            buffer[3] = ((uint64_t *) (data + 18))[0];
            buffer[4] = ((uint64_t *) (data + 24))[0];
            buffer[5] = ((uint64_t *) (data + 30))[0];
            buffer[6] = ((uint64_t *) (data + 36))[0];
            buffer[7] = ((uint64_t *) (data + 42))[0];
        }

        void load25(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 6))[0] >> 2;
            buffer[2] = ((uint64_t *) (data + 12))[0] >> 4;
            buffer[3] = ((uint64_t *) (data + 18))[0] >> 6;
            buffer[4] = ((uint64_t *) (data + 25))[0];
            buffer[5] = ((uint64_t *) (data + 31))[0] >> 2;
            buffer[6] = ((uint64_t *) (data + 37))[0] >> 4;
            buffer[7] = ((uint64_t *) (data + 43))[0] >> 6;
        }

        void load26(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 6))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 13))[0];
            buffer[3] = ((uint64_t *) (data + 19))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 26))[0];
            buffer[5] = ((uint64_t *) (data + 32))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 39))[0];
            buffer[7] = ((uint64_t *) (data + 45))[0] >> 4;
        }

        void load27(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 6))[0] >> 6;
            buffer[2] = ((uint64_t *) (data + 13))[0] >> 4;
            buffer[3] = ((uint64_t *) (data + 20))[0] >> 2;
            buffer[4] = ((uint64_t *) (data + 27))[0];
            buffer[5] = ((uint64_t *) (data + 33))[0] >> 6;
            buffer[6] = ((uint64_t *) (data + 40))[0] >> 4;
            buffer[7] = ((uint64_t *) (data + 47))[0] >> 2;
        }

        void load28(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0];
            buffer[2] = ((uint64_t *) (data + 14))[0];
            buffer[3] = ((uint64_t *) (data + 21))[0];
            buffer[4] = ((uint64_t *) (data + 28))[0];
            buffer[5] = ((uint64_t *) (data + 35))[0];
            buffer[6] = ((uint64_t *) (data + 42))[0];
            buffer[7] = ((uint64_t *) (data + 49))[0];
        }

        void load29(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 2;
            buffer[2] = ((uint64_t *) (data + 14))[0] >> 4;
            buffer[3] = ((uint64_t *) (data + 21))[0] >> 6;
            buffer[4] = ((uint64_t *) (data + 29))[0];
            buffer[5] = ((uint64_t *) (data + 36))[0] >> 2;
            buffer[6] = ((uint64_t *) (data + 43))[0] >> 4;
            buffer[7] = ((uint64_t *) (data + 50))[0] >> 6;
        }

        void load30(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 4;
            buffer[2] = ((uint64_t *) (data + 15))[0];
            buffer[3] = ((uint64_t *) (data + 22))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 30))[0];
            buffer[5] = ((uint64_t *) (data + 37))[0] >> 4;
            buffer[6] = ((uint64_t *) (data + 45))[0];
            buffer[7] = ((uint64_t *) (data + 52))[0] >> 4;
        }

        void load31(const uint8_t *data, uint64_t *buffer) {
            buffer[0] = ((uint64_t *) data)[0];
            buffer[1] = ((uint64_t *) (data + 7))[0] >> 6;
            buffer[2] = ((uint64_t *) (data + 11))[0] >> 5;
            buffer[3] = ((uint64_t *) (data + 15))[0] >> 4;
            buffer[4] = ((uint64_t *) (data + 19))[0] >> 3;
            buffer[5] = ((uint64_t *) (data + 23))[0] >> 2;
            buffer[6] = ((uint64_t *) (data + 31))[0];
            buffer[7] = ((uint64_t *) (data + 38))[0] >> 6;
        }

        void
        (*loaders[32])(const uint8_t *, uint64_t *) = {load1, load1, load2, load3, load4, load5, load6, load7, load8,
                                                       load9, load10, load11, load12, load13, load14, load15, load16,
                                                       load17, load18, load19, load20, load21, load22, load23, load24,
                                                       load25, load26, load27, load28, load29, load30, load31};

        uint32_t entryInBlocks[32][8] = {
                {0,  0,  0,  0,  0,  0,  0,  0},
                {64, 64, 64, 64, 64, 64, 64, 64},
                {32, 32, 32, 32, 32, 32, 32, 32},
                {21, 19, 21, 19, 21, 19, 21, 19},
                {16, 16, 16, 16, 16, 16, 16, 16},
                {12, 12, 12, 12, 12, 12, 12, 12},
                {10, 10, 10, 10, 10, 10, 10, 10},
                {9,  8,  8,  8,  8,  8,  8,  8},
                {8,  8,  8,  8,  8,  8,  8,  8},
                {7,  6,  6,  6,  7,  7,  6,  6},
                {6,  6,  6,  6,  6,  6,  6,  6},
                {5,  5,  5,  5,  5,  5,  5,  5},
                {5,  5,  5,  5,  5,  5,  5,  5},
                {4,  4,  4,  4,  4,  4,  4,  4},
                {4,  4,  4,  4,  4,  4,  4,  4},
                {4,  4,  4,  4,  4,  4,  4,  4},
                {4,  4,  4,  4,  4,  4,  4,  4},
                {3,  3,  3,  3,  3,  3,  3,  3},
                {3,  3,  3,  3,  3,  3,  3,  3},
                {3,  3,  3,  3,  3,  3,  3,  3},
                {3,  3,  3,  3,  3,  3,  3,  3},
                {3,  2,  3,  3,  2,  3,  3,  2},
                {2,  2,  2,  2,  2,  2,  2,  2},
                {2,  2,  2,  2,  2,  2,  2,  2},
                {2,  2,  2,  2,  2,  2,  2,  2},
                {2,  2,  2,  2,  2,  2,  2,  2},
                {2,  2,  2,  2,  2,  2,  2,  2},
                {2,  2,  2,  2,  2,  2,  2,  2},
                {2,  2,  2,  2,  2,  2,  2,  2},
                {2,  2,  2,  2,  2,  2,  2,  2},
                {2,  2,  2,  2,  2,  2,  2,  2},
                {2,  1,  1,  1,  1,  2,  2,  1}
        };

        void write1(__m512i res, uint64_t *bitmap, uint64_t extract) {}

        void write2(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 32) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 32) - 1);
            bitmap[0] |= bits << 32;
            bits = _pext_u64(res[2], extract) & ((1L << 32) - 1);
            bitmap[1] |= bits << 0;
            bits = _pext_u64(res[3], extract) & ((1L << 32) - 1);
            bitmap[1] |= bits << 32;
            bits = _pext_u64(res[4], extract) & ((1L << 32) - 1);
            bitmap[2] |= bits << 0;
            bits = _pext_u64(res[5], extract) & ((1L << 32) - 1);
            bitmap[2] |= bits << 32;
            bits = _pext_u64(res[6], extract) & ((1L << 32) - 1);
            bitmap[3] |= bits << 0;
            bits = _pext_u64(res[7], extract) & ((1L << 32) - 1);
            bitmap[3] |= bits << 32;
        }

        void write3(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 21) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 19) - 1);
            bitmap[0] |= bits << 21;
            bits = _pext_u64(res[2], extract) & ((1L << 21) - 1);
            bitmap[0] |= bits << 40;
            bits = _pext_u64(res[3], extract) & ((1L << 19) - 1);
            bitmap[0] |= bits << 61;
            bitmap[1] |= bits >> 3;
            bits = _pext_u64(res[4], extract) & ((1L << 21) - 1);
            bitmap[1] |= bits << 16;
            bits = _pext_u64(res[5], extract) & ((1L << 19) - 1);
            bitmap[1] |= bits << 37;
            bits = _pext_u64(res[6], extract) & ((1L << 21) - 1);
            bitmap[1] |= bits << 56;
            bitmap[2] |= bits >> 8;
            bits = _pext_u64(res[7], extract) & ((1L << 19) - 1);
            bitmap[2] |= bits << 13;
        }

        void write4(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 16) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 16) - 1);
            bitmap[0] |= bits << 16;
            bits = _pext_u64(res[2], extract) & ((1L << 16) - 1);
            bitmap[0] |= bits << 32;
            bits = _pext_u64(res[3], extract) & ((1L << 16) - 1);
            bitmap[0] |= bits << 48;
            bits = _pext_u64(res[4], extract) & ((1L << 16) - 1);
            bitmap[1] |= bits << 0;
            bits = _pext_u64(res[5], extract) & ((1L << 16) - 1);
            bitmap[1] |= bits << 16;
            bits = _pext_u64(res[6], extract) & ((1L << 16) - 1);
            bitmap[1] |= bits << 32;
            bits = _pext_u64(res[7], extract) & ((1L << 16) - 1);
            bitmap[1] |= bits << 48;
        }

        void write5(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[2], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 24;
            bits = _pext_u64(res[3], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 36;
            bits = _pext_u64(res[4], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 48;
            bits = _pext_u64(res[5], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 60;
            bitmap[1] |= bits >> 4;
            bits = _pext_u64(res[6], extract) & ((1L << 12) - 1);
            bitmap[1] |= bits << 8;
            bits = _pext_u64(res[7], extract) & ((1L << 12) - 1);
            bitmap[1] |= bits << 20;
        }

        void write6(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[2], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 20;
            bits = _pext_u64(res[3], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 30;
            bits = _pext_u64(res[4], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 40;
            bits = _pext_u64(res[5], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 50;
            bits = _pext_u64(res[6], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 60;
            bitmap[1] |= bits >> 4;
            bits = _pext_u64(res[7], extract) & ((1L << 10) - 1);
            bitmap[1] |= bits << 6;
        }

        void write7(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 9) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 9;
            bits = _pext_u64(res[2], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 17;
            bits = _pext_u64(res[3], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 25;
            bits = _pext_u64(res[4], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 33;
            bits = _pext_u64(res[5], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 41;
            bits = _pext_u64(res[6], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 49;
            bits = _pext_u64(res[7], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 57;
            bitmap[1] |= bits >> 7;
        }

        void write8(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[2], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 16;
            bits = _pext_u64(res[3], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 24;
            bits = _pext_u64(res[4], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 32;
            bits = _pext_u64(res[5], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 40;
            bits = _pext_u64(res[6], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 48;
            bits = _pext_u64(res[7], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 56;
        }

        void write9(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 7) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 7;
            bits = _pext_u64(res[2], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 13;
            bits = _pext_u64(res[3], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 19;
            bits = _pext_u64(res[4], extract) & ((1L << 7) - 1);
            bitmap[0] |= bits << 25;
            bits = _pext_u64(res[5], extract) & ((1L << 7) - 1);
            bitmap[0] |= bits << 32;
            bits = _pext_u64(res[6], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 39;
            bits = _pext_u64(res[7], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 45;
        }

        void write10(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[2], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[3], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 18;
            bits = _pext_u64(res[4], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 24;
            bits = _pext_u64(res[5], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 30;
            bits = _pext_u64(res[6], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 36;
            bits = _pext_u64(res[7], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 42;
        }

        void write11(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 5;
            bits = _pext_u64(res[2], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[3], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 15;
            bits = _pext_u64(res[4], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 20;
            bits = _pext_u64(res[5], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 25;
            bits = _pext_u64(res[6], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 30;
            bits = _pext_u64(res[7], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 35;
        }

        void write12(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 5;
            bits = _pext_u64(res[2], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[3], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 15;
            bits = _pext_u64(res[4], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 20;
            bits = _pext_u64(res[5], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 25;
            bits = _pext_u64(res[6], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 30;
            bits = _pext_u64(res[7], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 35;
        }

        void write13(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[2], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[3], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[4], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 16;
            bits = _pext_u64(res[5], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 20;
            bits = _pext_u64(res[6], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 24;
            bits = _pext_u64(res[7], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 28;
        }

        void write14(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[2], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[3], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[4], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 16;
            bits = _pext_u64(res[5], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 20;
            bits = _pext_u64(res[6], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 24;
            bits = _pext_u64(res[7], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 28;
        }

        void write15(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[2], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[3], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[4], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 16;
            bits = _pext_u64(res[5], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 20;
            bits = _pext_u64(res[6], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 24;
            bits = _pext_u64(res[7], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 28;
        }

        void write16(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[2], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[3], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[4], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 16;
            bits = _pext_u64(res[5], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 20;
            bits = _pext_u64(res[6], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 24;
            bits = _pext_u64(res[7], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 28;
        }

        void write17(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 3;
            bits = _pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 9;
            bits = _pext_u64(res[4], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 15;
            bits = _pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 18;
            bits = _pext_u64(res[7], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 21;
        }

        void write18(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 3;
            bits = _pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 9;
            bits = _pext_u64(res[4], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 15;
            bits = _pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 18;
            bits = _pext_u64(res[7], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 21;
        }

        void write19(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 3;
            bits = _pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 9;
            bits = _pext_u64(res[4], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 15;
            bits = _pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 18;
            bits = _pext_u64(res[7], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 21;
        }

        void write20(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 3;
            bits = _pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 9;
            bits = _pext_u64(res[4], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 15;
            bits = _pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 18;
            bits = _pext_u64(res[7], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 21;
        }

        void write21(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 3;
            bits = _pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 5;
            bits = _pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 11;
            bits = _pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 13;
            bits = _pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 16;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 19;
        }

        void write22(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void write23(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void write24(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void write25(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void write26(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void write27(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void write28(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void write29(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void write30(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = _pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void write31(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = _pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = _pext_u64(res[1], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 2;
            bits = _pext_u64(res[2], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 3;
            bits = _pext_u64(res[3], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 4;
            bits = _pext_u64(res[4], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 5;
            bits = _pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = _pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = _pext_u64(res[7], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 10;
        }

        void
        (*writers[32])(__m512i, uint64_t *, uint64_t) = {write1, write1, write2, write3, write4, write5, write6, write7,
                                                         write8, write9, write10, write11, write12, write13, write14,
                                                         write15, write16, write17, write18, write19, write20, write21,
                                                         write22, write23, write24, write25, write26, write27, write28,
                                                         write29, write30, write31};

        void writeinv1(__m512i res, uint64_t *bitmap, uint64_t extract) {}

        void writeinv2(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 32) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 32) - 1);
            bitmap[0] |= bits << 32;
            bits = ~_pext_u64(res[2], extract) & ((1L << 32) - 1);
            bitmap[1] |= bits << 0;
            bits = ~_pext_u64(res[3], extract) & ((1L << 32) - 1);
            bitmap[1] |= bits << 32;
            bits = ~_pext_u64(res[4], extract) & ((1L << 32) - 1);
            bitmap[2] |= bits << 0;
            bits = ~_pext_u64(res[5], extract) & ((1L << 32) - 1);
            bitmap[2] |= bits << 32;
            bits = ~_pext_u64(res[6], extract) & ((1L << 32) - 1);
            bitmap[3] |= bits << 0;
            bits = ~_pext_u64(res[7], extract) & ((1L << 32) - 1);
            bitmap[3] |= bits << 32;
        }

        void writeinv3(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 21) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 19) - 1);
            bitmap[0] |= bits << 21;
            bits = ~_pext_u64(res[2], extract) & ((1L << 21) - 1);
            bitmap[0] |= bits << 40;
            bits = ~_pext_u64(res[3], extract) & ((1L << 19) - 1);
            bitmap[0] |= bits << 61;
            bitmap[1] |= bits >> 3;
            bits = ~_pext_u64(res[4], extract) & ((1L << 21) - 1);
            bitmap[1] |= bits << 16;
            bits = ~_pext_u64(res[5], extract) & ((1L << 19) - 1);
            bitmap[1] |= bits << 37;
            bits = ~_pext_u64(res[6], extract) & ((1L << 21) - 1);
            bitmap[1] |= bits << 56;
            bitmap[2] |= bits >> 8;
            bits = ~_pext_u64(res[7], extract) & ((1L << 19) - 1);
            bitmap[2] |= bits << 13;
        }

        void writeinv4(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 16) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 16) - 1);
            bitmap[0] |= bits << 16;
            bits = ~_pext_u64(res[2], extract) & ((1L << 16) - 1);
            bitmap[0] |= bits << 32;
            bits = ~_pext_u64(res[3], extract) & ((1L << 16) - 1);
            bitmap[0] |= bits << 48;
            bits = ~_pext_u64(res[4], extract) & ((1L << 16) - 1);
            bitmap[1] |= bits << 0;
            bits = ~_pext_u64(res[5], extract) & ((1L << 16) - 1);
            bitmap[1] |= bits << 16;
            bits = ~_pext_u64(res[6], extract) & ((1L << 16) - 1);
            bitmap[1] |= bits << 32;
            bits = ~_pext_u64(res[7], extract) & ((1L << 16) - 1);
            bitmap[1] |= bits << 48;
        }

        void writeinv5(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[2], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 24;
            bits = ~_pext_u64(res[3], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 36;
            bits = ~_pext_u64(res[4], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 48;
            bits = ~_pext_u64(res[5], extract) & ((1L << 12) - 1);
            bitmap[0] |= bits << 60;
            bitmap[1] |= bits >> 4;
            bits = ~_pext_u64(res[6], extract) & ((1L << 12) - 1);
            bitmap[1] |= bits << 8;
            bits = ~_pext_u64(res[7], extract) & ((1L << 12) - 1);
            bitmap[1] |= bits << 20;
        }

        void writeinv6(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[2], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 20;
            bits = ~_pext_u64(res[3], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 30;
            bits = ~_pext_u64(res[4], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 40;
            bits = ~_pext_u64(res[5], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 50;
            bits = ~_pext_u64(res[6], extract) & ((1L << 10) - 1);
            bitmap[0] |= bits << 60;
            bitmap[1] |= bits >> 4;
            bits = ~_pext_u64(res[7], extract) & ((1L << 10) - 1);
            bitmap[1] |= bits << 6;
        }

        void writeinv7(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 9) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 9;
            bits = ~_pext_u64(res[2], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 17;
            bits = ~_pext_u64(res[3], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 25;
            bits = ~_pext_u64(res[4], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 33;
            bits = ~_pext_u64(res[5], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 41;
            bits = ~_pext_u64(res[6], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 49;
            bits = ~_pext_u64(res[7], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 57;
            bitmap[1] |= bits >> 7;
        }

        void writeinv8(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[2], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 16;
            bits = ~_pext_u64(res[3], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 24;
            bits = ~_pext_u64(res[4], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 32;
            bits = ~_pext_u64(res[5], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 40;
            bits = ~_pext_u64(res[6], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 48;
            bits = ~_pext_u64(res[7], extract) & ((1L << 8) - 1);
            bitmap[0] |= bits << 56;
        }

        void writeinv9(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 7) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 7;
            bits = ~_pext_u64(res[2], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 13;
            bits = ~_pext_u64(res[3], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 19;
            bits = ~_pext_u64(res[4], extract) & ((1L << 7) - 1);
            bitmap[0] |= bits << 25;
            bits = ~_pext_u64(res[5], extract) & ((1L << 7) - 1);
            bitmap[0] |= bits << 32;
            bits = ~_pext_u64(res[6], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 39;
            bits = ~_pext_u64(res[7], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 45;
        }

        void writeinv10(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[2], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[3], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 18;
            bits = ~_pext_u64(res[4], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 24;
            bits = ~_pext_u64(res[5], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 30;
            bits = ~_pext_u64(res[6], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 36;
            bits = ~_pext_u64(res[7], extract) & ((1L << 6) - 1);
            bitmap[0] |= bits << 42;
        }

        void writeinv11(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 5;
            bits = ~_pext_u64(res[2], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[3], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 15;
            bits = ~_pext_u64(res[4], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 20;
            bits = ~_pext_u64(res[5], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 25;
            bits = ~_pext_u64(res[6], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 30;
            bits = ~_pext_u64(res[7], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 35;
        }

        void writeinv12(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 5;
            bits = ~_pext_u64(res[2], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[3], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 15;
            bits = ~_pext_u64(res[4], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 20;
            bits = ~_pext_u64(res[5], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 25;
            bits = ~_pext_u64(res[6], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 30;
            bits = ~_pext_u64(res[7], extract) & ((1L << 5) - 1);
            bitmap[0] |= bits << 35;
        }

        void writeinv13(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[2], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[3], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[4], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 16;
            bits = ~_pext_u64(res[5], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 20;
            bits = ~_pext_u64(res[6], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 24;
            bits = ~_pext_u64(res[7], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 28;
        }

        void writeinv14(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[2], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[3], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[4], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 16;
            bits = ~_pext_u64(res[5], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 20;
            bits = ~_pext_u64(res[6], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 24;
            bits = ~_pext_u64(res[7], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 28;
        }

        void writeinv15(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[2], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[3], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[4], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 16;
            bits = ~_pext_u64(res[5], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 20;
            bits = ~_pext_u64(res[6], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 24;
            bits = ~_pext_u64(res[7], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 28;
        }

        void writeinv16(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[2], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[3], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[4], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 16;
            bits = ~_pext_u64(res[5], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 20;
            bits = ~_pext_u64(res[6], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 24;
            bits = ~_pext_u64(res[7], extract) & ((1L << 4) - 1);
            bitmap[0] |= bits << 28;
        }

        void writeinv17(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 3;
            bits = ~_pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 9;
            bits = ~_pext_u64(res[4], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 15;
            bits = ~_pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 18;
            bits = ~_pext_u64(res[7], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 21;
        }

        void writeinv18(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 3;
            bits = ~_pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 9;
            bits = ~_pext_u64(res[4], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 15;
            bits = ~_pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 18;
            bits = ~_pext_u64(res[7], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 21;
        }

        void writeinv19(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 3;
            bits = ~_pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 9;
            bits = ~_pext_u64(res[4], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 15;
            bits = ~_pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 18;
            bits = ~_pext_u64(res[7], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 21;
        }

        void writeinv20(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 3;
            bits = ~_pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 9;
            bits = ~_pext_u64(res[4], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 15;
            bits = ~_pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 18;
            bits = ~_pext_u64(res[7], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 21;
        }

        void writeinv21(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 3;
            bits = ~_pext_u64(res[2], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 5;
            bits = ~_pext_u64(res[3], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 11;
            bits = ~_pext_u64(res[5], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 13;
            bits = ~_pext_u64(res[6], extract) & ((1L << 3) - 1);
            bitmap[0] |= bits << 16;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 19;
        }

        void writeinv22(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void writeinv23(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void writeinv24(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void writeinv25(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void writeinv26(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void writeinv27(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void writeinv28(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void writeinv29(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void writeinv30(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[3], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[4], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 10;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 12;
            bits = ~_pext_u64(res[7], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 14;
        }

        void writeinv31(__m512i res, uint64_t *bitmap, uint64_t extract) {
            uint64_t bits = 0;
            bits = ~_pext_u64(res[0], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 0;
            bits = ~_pext_u64(res[1], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 2;
            bits = ~_pext_u64(res[2], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 3;
            bits = ~_pext_u64(res[3], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 4;
            bits = ~_pext_u64(res[4], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 5;
            bits = ~_pext_u64(res[5], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 6;
            bits = ~_pext_u64(res[6], extract) & ((1L << 2) - 1);
            bitmap[0] |= bits << 8;
            bits = ~_pext_u64(res[7], extract) & ((1L << 1) - 1);
            bitmap[0] |= bits << 10;
        }

        void
        (*writeinvs[32])(__m512i, uint64_t *, uint64_t) = {writeinv1, writeinv1, writeinv2, writeinv3, writeinv4, writeinv5, writeinv6, writeinv7,
                                                            writeinv8, writeinv9, writeinv10, writeinv11, writeinv12, writeinv13, writeinv14,
                                                            writeinv15, writeinv16, writeinv17, writeinv18, writeinv19, writeinv20, writeinv21,
                                                            writeinv22, writeinv23, writeinv24, writeinv25, writeinv26, writeinv27, writeinv28,
                                                            writeinv29, writeinv30, writeinv31};

    }
}