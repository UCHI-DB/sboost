//
// Created by Hao Jiang on 12/1/20.
// This benchmark is to evaluate whether it is necessary to create dedicated loader functions
//
#include <benchmark/benchmark.h>
#include "byteutils.h"
#include "sboost.h"
#include "loader.h"


class LoaderBenchmark : public benchmark::Fixture {
protected:
    uint32_t *data_;
    uint8_t *output_;
    uint32_t numEntry_;
    uint8_t bitWidth_;
    uint64_t *res_;
public:
    // add members as needed

    LoaderBenchmark() {
        numEntry_ = 100000;
        bitWidth_ = 11;
        output_ = (uint8_t *) malloc(sizeof(uint32_t) * numEntry_);
        data_ = (uint32_t *) malloc(sizeof(uint32_t) * numEntry_);
        res_ = (uint64_t *) malloc(sizeof(uint64_t) * (numEntry_ + 1) / 64);

        for (uint32_t i = 0; i < numEntry_; ++i) {
            data_[i] = i;
        }
        ::sboost::byteutils::bitpack(data_, numEntry_, bitWidth_, output_);
    }

    virtual ~LoaderBenchmark() {
        free(data_);
        free(output_);
        free(res_);
    }
};

BENCHMARK_F(LoaderBenchmark, Dynamic)(benchmark::State &state) {
    uint64_t buffer_[8];

    for (auto _ : state) {
        sboost::SortedBitpack sbp(bitWidth_, 134);
//        sbp.geqGroup2(output_, buffer_);
    }
}

BENCHMARK_F(LoaderBenchmark, Template)(benchmark::State &state) {
    uint64_t buffer_[8];

    for (auto _ : state) {
        sboost::SortedBitpack sbp(bitWidth_, 134);
//        sbp.geqGroup(output_, buffer_);
    }
}


