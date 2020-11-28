//
// Created by harper on 2/19/20.
//

#include <gtest/gtest.h>
#include <fstream>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "deltabp.h"
#include "../bitmap_writer.h"

using namespace sboost;
using namespace sboost::encoding;

class DeltaBP : public ::testing::Test {
protected:
    uint8_t *content;
    uint32_t file_size;
    int fd;


    virtual void SetUp() override {
        struct stat st;
        stat("testres/sboost/deltabpcontent", &st);
        file_size = st.st_size;
        fd = open("testres/sboost/deltabpcontent", O_RDONLY, 0);
        assert(fd != -1);
        //Execute mmap
        void *mmappedData = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
        assert(mmappedData != MAP_FAILED);
        content = (uint8_t *) mmappedData;
    }

    virtual void TearDown() override {
        munmap(content, file_size);
        close(fd);
    }
};


TEST_F(DeltaBP, Equal) {
    uint64_t output[10000] = {0};

    int pred = 1020;

    uint64_t expect[10000] = {0};
    BitmapWriter expectedBitmap(expect, 0);
    std::ifstream infile("testres/sboost/deltabpval");
    int lineval;
    while (infile >> lineval) {
        expectedBitmap.appendBits(lineval == pred, 1);
    }

    deltabp::equal(content, output, 0, 50000, pred);


    for (int i = 0; i < 781; ++i) {
        ASSERT_EQ(output[i], expect[i]) << i;
    }
    ASSERT_EQ(output[781] & 0xFFFF, expect[781] & 0xffff);
}

TEST_F(DeltaBP, Less) {
    uint64_t output[10000] = {0};

    int pred = 1249;

    uint64_t expect[10000] = {0};
    BitmapWriter expectedBitmap(expect, 0);
    std::ifstream infile("testres/sboost/deltabpval");
    int lineval;
    while (infile >> lineval) {
        expectedBitmap.appendBits(lineval < pred, 1);
    }

    deltabp::less(content, output, 0, 50000, pred);

    for (int i = 0; i < 781; ++i) {
        ASSERT_EQ(output[i], expect[i]) << i;
    }
    ASSERT_EQ(output[781] & 0xFFFF, expect[781] & 0xffff);
}

TEST_F(DeltaBP, Greater) {
    uint64_t output[10000] = {0};

    int pred = 1020;

    uint64_t expect[10000] = {0};
    BitmapWriter expectedBitmap(expect, 0);
    std::ifstream infile("testres/sboost/deltabpval");
    int lineval;
    while (infile >> lineval) {
        expectedBitmap.appendBits(lineval > pred, 1);
    }

    deltabp::greater(content, output, 0, 50000, pred);

    for (int i = 0; i < 781; ++i) {
        ASSERT_EQ(output[i], expect[i]) << i;
    }
    ASSERT_EQ(output[781] & 0xFFFF, expect[781] & 0xffff);
}

TEST_F(DeltaBP, Between) {
    uint64_t output[10000] = {0};

    int ub = 2010;
    int lb = 424;

    uint64_t expect[10000] = {0};
    BitmapWriter expectedBitmap(expect, 0);
    std::ifstream infile("testres/sboost/deltabpval");
    int lineval;
    while (infile >> lineval) {
        expectedBitmap.appendBits(lineval >= lb && lineval <= ub, 1);
    }

    deltabp::between(content, output, 0, 50000, lb, ub);

    for (int i = 0; i < 781; ++i) {
        ASSERT_EQ(output[i], expect[i]) << i;
    }
    ASSERT_EQ(output[781] & 0xFFFF, expect[781] & 0xffff);
}

TEST_F(DeltaBP, Rangele) {
    uint64_t output[10000] = {0};

    int ub = 2322;
    int lb = 1421;

    uint64_t expect[10000] = {0};
    BitmapWriter expectedBitmap(expect, 0);
    std::ifstream infile("testres/sboost/deltabpval");
    int lineval;
    while (infile >> lineval) {
        expectedBitmap.appendBits(lineval >= lb && lineval < ub, 1);
    }

    deltabp::rangele(content, output, 0, 50000, lb, ub);

    for (int i = 0; i < 781; ++i) {
        ASSERT_EQ(output[i], expect[i]) << i;
    }
    ASSERT_EQ(output[781] & 0xFFFF, expect[781] & 0xffff);
}



