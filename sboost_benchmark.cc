//
// Created by Hao Jiang on 11/30/20.
//
// This benchmark is to study if we should template the loadNext function
//

#include <benchmark/benchmark.h>
#include "byteutils.h"
#include "sboost.h"


class SboostBenchmark : public benchmark::Fixture {
protected:
    uint32_t *data_;
    uint8_t *output_;
    uint32_t numEntry_;
    uint8_t bitWidth_;
    uint64_t *res_;
public:
    // add members as needed

    SboostBenchmark() {
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

    virtual ~SboostBenchmark() {
        free(data_);
        free(output_);
        free(res_);
    }
};

BENCHMARK_F(SboostBenchmark, Dynamic)(benchmark::State &state) {
    for (auto _ : state) {
        //run your benchmark
        sboost::Bitpack bp(11, 131);
        bp.geq(output_, numEntry_, res_, 0);
    }
}

BENCHMARK_F(SboostBenchmark, Template)(benchmark::State &state) {
    for (auto _ : state) {
        sboost::TemplateBitpack tbp(11, 131);
        tbp.geq(output_, numEntry_, res_, 0);
    }
}
