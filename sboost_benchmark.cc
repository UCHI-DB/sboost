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

//BENCHMARK_F(SboostBenchmark, Dynamic)(benchmark::State &state) {
//    for (auto _ : state) {
//        //run your benchmark
//        sboost::Bitpack bp(11, 131);
//        bp.geq(output_, numEntry_, res_, 0);
//    }
//}
//
//BENCHMARK_F(SboostBenchmark, Template)(benchmark::State &state) {
//    for (auto _ : state) {
//        sboost::TemplateBitpack tbp(11, 131);
//        tbp.geq(output_, numEntry_, res_, 0);
//    }
//}

int32_t binary_search(vector<uint32_t> &data, int target) {
    auto begin = 0;
    auto end = data.size() - 1;
    while (begin < end) {
        auto current = (begin + end + 1) / 2;
        if (data[current] < target) {
            begin = current;
        } else if (data[current] == target) {
            return current;
        } else {
            end = current - 1;
        }
    }
    return begin;
}

int32_t binary_search_packed(uint8_t* data, int target, uint8_t offset) {
    
}

class SearchBenchmark : public benchmark::Fixture {
protected:
    vector<uint32_t> data_;
    uint8_t *output_;
    uint32_t numEntry_;
    uint8_t bitWidth_;
    uint64_t *res_;
    int32_t result_;
public:

    SearchBenchmark() {
        numEntry_ = 1024;
        bitWidth_ = 17;
        output_ = (uint8_t *) malloc(sizeof(uint32_t) * numEntry_);

        for (uint32_t i = 0; i < numEntry_; ++i) {
            data_.push_back(i);
        }
        ::sboost::byteutils::bitpack(data_.data(), numEntry_, bitWidth_, output_);
    }

    virtual ~SearchBenchmark() {
        free(output_);
        free(res_);
    }
};

BENCHMARK_F(SearchBenchmark, STL)(benchmark::State &state) {
    for (auto _: state) {
//        for (int i = 0; i < numEntry_; ++i) {
        auto i = numEntry_ / 5;
        result_ = binary_search(data_, i);
//        }
    }
}

BENCHMARK_F(SearchBenchmark, SBoost)(benchmark::State &state) {
    for (auto _ : state) {
//        for (int i = 0; i < numEntry_; ++i) {
        auto i = numEntry_ / 5;
        sboost::SortedBitpack sbp(bitWidth_, i);
        result_ = sbp.geq(output_, numEntry_);
//        }
    }
}

BENCHMARK_F(SearchBenchmark, SBoostSeq)(benchmark::State &state) {
    for (auto _ : state) {
//        for (int i = 0; i < numEntry_; ++i) {
        auto i = numEntry_ / 5;
        sboost::Bitpack bp(bitWidth_, i);
        result_ = bp.geq(output_, numEntry_);
//        }
    }
}