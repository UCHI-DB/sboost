//
// Created by harper on 9/24/19.
//

#include <gtest/gtest.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "rlehybrid.h"

using namespace sboost::encoding::rlehybrid;

TEST(RLEHybrid, equal) {
    struct stat st;
    stat("testres/sboost/rlecontent", &st);
    uint32_t filesize = st.st_size;
    int fd = open("testres/sboost/rlecontent", O_RDONLY, 0);
    assert(fd != -1);
    //Execute mmap
    void *mmappedData = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
    assert(mmappedData != MAP_FAILED);

    uint64_t output[10000] = {0};

    equal(((uint8_t *) mmappedData) + 1, output, 0, 3, 15000, 3);

    //Cleanup
    int rc = munmap(mmappedData, filesize);
    assert(rc == 0);
    close(fd);

    uint64_t exp[10] = {
            0x218012640444A10, 0xA20400042020005A, 0x24000184149010F, 0x8448308000120002,
            0x3108154CA2000204, 0x80405C0088444832, 0x490043A00404246C, 0x2324000201206016,
            0x9400220004146881, 0xB120130C18C60040
    };

    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(output[i], exp[i]) << i;
    }
    return;
}

TEST(SegmentReaderTest, Next) {
    struct stat st;
    stat("testres/sboost/rlecontent", &st);
    uint32_t filesize = st.st_size;
    int fd = open("testres/sboost/rlecontent", O_RDONLY, 0);
    assert(fd != -1);
    //Execute mmap
    void *mmappedData = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
    assert(mmappedData != MAP_FAILED);
    const uint8_t *data = (const uint8_t *) mmappedData;
    auto bitwidth = data[0];
    SegmentReader reader(data + 1, bitwidth, 15000);

    int counter = 0;
    int num_entry = 0;
    while (reader.hasNext()) {
        auto segment = reader.next();
        num_entry += segment.num_entry_;
        ++counter;
    }

    EXPECT_EQ(30, counter);
    EXPECT_EQ(15000, num_entry);
}