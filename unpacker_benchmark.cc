//
// Created by harper on 3/2/20.
//

#include <benchmark/benchmark.h>
#include "byteutils.h"
#include "unpacker.h"

class UnpackerBenchmark : public benchmark::Fixture {
protected:
    uint8_t *data_;
    uint32_t *output_;
    uint64_t numEntry_;
    uint8_t bitWidth_;
public:
    // add members as needed

    UnpackerBenchmark() {
        numEntry_ = 1000000;
        bitWidth_ = 11;
        uint32_t mask = (1 << bitWidth_) - 1;
        data_ = (uint8_t *) malloc((bitWidth_ * numEntry_ + 8) >> 3);
        output_ = (uint32_t *) malloc(sizeof(uint32_t) * numEntry_);

        srand(time(NULL));
        uint32_t *values = (uint32_t *) malloc(sizeof(int32_t) * numEntry_);
        for (uint32_t i = 0; i < numEntry_; ++i) {
            values[i] = static_cast<uint32_t>(rand() & mask);
        }
        ::sboost::byteutils::bitpack(values, numEntry_, bitWidth_, data_);
        free(values);
    }

    virtual ~UnpackerBenchmark() {
        free(data_);
        free(output_);
    }
};

BENCHMARK_F(UnpackerBenchmark, Scalar)(benchmark::State &state) {
    for (auto _ : state) {
        //run your benchmark
        sboost::unpackScalar(data_, numEntry_, bitWidth_, output_);
    }
}

BENCHMARK_F(UnpackerBenchmark, SBoost)(benchmark::State &state) {
    for (auto _ : state) {
        sboost::unpacks[bitWidth_](data_, numEntry_, output_);
    }
}
