//
// Created by harper on 9/30/19.
//

#include <cstring>
#include "sboost.h"
#include "loader.h"
#include "byteutils.h"

namespace sboost {

    uint64_t
    loadNext(const uint8_t *data, uint32_t bitwidth, uint32_t *byteindex, uint32_t *bitoffset, uint32_t *entryInBlock) {
        // Load next block and align it
        uint64_t loaded = (((uint64_t *) (data + *byteindex))[0] >> *bitoffset);

        // Update index and offset
        *entryInBlock = (64 - *bitoffset) / bitwidth;
        uint32_t bitadvance = (*entryInBlock) * bitwidth + (*bitoffset);
        *bitoffset = bitadvance & 0x7;
        *byteindex += bitadvance >> 3;
        return loaded;
    }

    uint8_t
    writeNext(uint64_t *res, uint64_t bits, uint32_t entryInBlock, uint32_t *resindex, uint32_t *resoffset) {
        res[*resindex] |= bits << *resoffset;
        *resoffset += entryInBlock;
        if (*resoffset >= 64) {
            // Be aware that we do not check resindex against rescount here so
            // resindex may be 1 larger than rescount if rescount is a multiple of 64
            // and the res[resindex] actually overflow the array, but as it did not write
            // anything it should be fine. But be aware of this in case it causes any bugs
            *resindex += 1;
            *resoffset &= 0x3F;
            if (*resoffset != 0)
                res[*resindex] |= bits >> (entryInBlock - *resoffset);
        }
        return _mm_popcnt_u64(bits);
    }


    static uint32_t lowestBit(uint64_t input) {
        return _mm_popcnt_u64((input & (input - 1) ^ input) - 1);
    }

    const uint64_t MASKS_64[] = {0, 0, 0x5555555555555555L, 0x36DB6DB6DB6DB6DBL, 0x7777777777777777L,
                                 0x7BDEF7BDEF7BDEFL,
                                 0x7DF7DF7DF7DF7DFL, 0x3F7EFDFBF7EFDFBFL, 0x7F7F7F7F7F7F7F7FL, 0x3FDFEFF7FBFDFEFFL,
                                 0x7FDFF7FDFF7FDFFL, 0x3FF7FEFFDFFBFFL, 0x7FF7FF7FF7FF7FFL, 0x7FFBFFDFFEFFFL,
                                 0x7FFDFFF7FFDFFFL, 0x7FFEFFFDFFFBFFFL, 0x7FFF7FFF7FFF7FFFL, 0x3FFFDFFFEFFFFL,
                                 0x1FFFF7FFFDFFFFL, 0xFFFFDFFFFBFFFFL, 0x7FFFF7FFFF7FFFFL, 0x3FFFFDFFFFEFFFFFL,
                                 0x7FFFFDFFFFFL, 0x1FFFFFBFFFFFL, 0x7FFFFF7FFFFFL, 0x1FFFFFEFFFFFFL, 0x7FFFFFDFFFFFFL,
                                 0x1FFFFFFBFFFFFFL, 0x7FFFFFF7FFFFFFL, 0x1FFFFFFEFFFFFFFL, 0x7FFFFFFDFFFFFFFL,
                                 0x1FFFFFFFBFFFFFFFL,
    };

    extern const uint64_t EXTRACT_64[] = {0, 0,
                                          0xAAAAAAAAAAAAAAAAL, 0x4924924924924924L, 0x8888888888888888L,
                                          0x842108421084210L,
                                          0x820820820820820L, 0x4081020408102040L, 0x8080808080808080L,
                                          0x4020100804020100L,
                                          0x802008020080200L, 0x40080100200400L, 0x800800800800800L, 0x8004002001000L,
                                          0x80020008002000L, 0x800100020004000L, 0x8000800080008000L, 0x4000200010000L,
                                          0x20000800020000L, 0x100002000040000L, 0x800008000080000L,
                                          0x4000020000100000L,
                                          0x80000200000L, 0x200000400000L, 0x800000800000L, 0x2000001000000L,
                                          0x8000002000000L,
                                          0x20000004000000L, 0x80000008000000L, 0x200000010000000L, 0x800000020000000L,
                                          0x2000000040000000L,
    };

    Bitpack::Bitpack(uint32_t bitWidth, uint32_t target) {
        this->bitWidth = bitWidth;
        this->target = target;
        this->extract = EXTRACT_64[bitWidth];
        this->mask = _mm512_set1_epi64(MASKS_64[bitWidth]);
        this->msbmask = _mm512_set1_epi64(EXTRACT_64[bitWidth]);
        uint64_t singleSpan = byteutils::spanTo64(this->bitWidth, this->target);
        this->spanned = _mm512_set1_epi64(singleSpan);
        this->nspanned = _mm512_set1_epi64(~singleSpan);
        this->l2 = _mm512_and_si512(spanned, mask);
        this->g2 = _mm512_or_si512(spanned, msbmask);
    }

    Bitpack::Bitpack(uint32_t bitWidth, uint32_t t1, uint32_t t2) : Bitpack(bitWidth, t1) {
        this->bitWidth = bitWidth;
        this->target = t1;
        this->target2 = t2;
        this->extract = EXTRACT_64[bitWidth];
        this->target2 = t2;
        uint64_t singleSpan2 = byteutils::spanTo64(this->bitWidth, this->target2);
        this->spanned2 = _mm512_set1_epi64(singleSpan2);
        this->nspanned2 = _mm512_set1_epi64(~singleSpan2);
        this->l22 = _mm512_and_si512(spanned2, mask);
        this->g22 = _mm512_or_si512(spanned2, msbmask);
    }

    Bitpack::~Bitpack() {}

    void Bitpack::equal(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset) {
        uint64_t buffer[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entryInBlock[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t resindex = resoffset >> 6;
        resoffset &= 0x3F;

        while (counter < numEntry) {
            // Load next block and align it
            for (int i = 0; i < 8; i++) {
                buffer[i] = loadNext(data, bitWidth, &byteindex, &bitoffset, entryInBlock + i);
                counter += entryInBlock[i];
                if (counter > numEntry) {
                    entryInBlock[i] -= counter - numEntry;
                    counter = numEntry;
                }
            }
            // Use SBoost_old algorithm to compare the loaded block with spanned
            __m512i loaded = _mm512_setr_epi64(buffer[0], buffer[1], buffer[2], buffer[3],
                                               buffer[4], buffer[5], buffer[6], buffer[7]);
            __m512i d = _mm512_xor_si512(loaded, spanned);
            __m512i r = _mm512_or_si512(d, _mm512_add_epi64(_mm512_and_si512(d, mask), mask));

            // Use PEXT to collect result, use popcnt to count data
            for (int i = 0; i < 8; i++) {
                writeNext(res, ~_pext_u64(r[i], extract) & ((1L << entryInBlock[i]) - 1),
                          entryInBlock[i], &resindex, &resoffset);
            }
        }
    }

    void Bitpack::less(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset) {
        uint64_t buffer[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entryInBlock[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t resindex = resoffset >> 6;
        resoffset &= 0x3F;

        while (counter < numEntry) {
            // Load next block and align it
            for (int i = 0; i < 8; i++) {
                buffer[i] = loadNext(data, bitWidth, &byteindex, &bitoffset, entryInBlock + i);
                counter += entryInBlock[i];
                if (counter > numEntry) {
                    entryInBlock[i] -= counter - numEntry;
                    counter = numEntry;
                }
            }
            // Use SBoost_old algorithm to compare the loaded block with spanned
            __m512i loaded = _mm512_setr_epi64(buffer[0], buffer[1], buffer[2], buffer[3],
                                               buffer[4], buffer[5], buffer[6], buffer[7]);
            __m512i l = _mm512_sub_epi64(_mm512_or_si512(loaded, msbmask), l2);
            __m512i r = _mm512_and_si512(_mm512_or_si512(loaded, nspanned),
                                         _mm512_or_si512(_mm512_and_si512(loaded, nspanned), l));

            // Use PEXT to collect result, use popcnt to count data
            for (int i = 0; i < 8; i++) {
                writeNext(res, ~_pext_u64(r[i], extract) & ((1L << entryInBlock[i]) - 1),
                          entryInBlock[i], &resindex, &resoffset);
            }
        }
    }

    void Bitpack::geq(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset) {
        uint64_t buffer[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entryInBlock[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t resindex = resoffset >> 6;
        resoffset &= 0x3F;

        while (counter < numEntry) {
            // Load next block and align it
            for (int i = 0; i < 8; i++) {
                buffer[i] = loadNext(data, bitWidth, &byteindex, &bitoffset, entryInBlock + i);
                counter += entryInBlock[i];
                if (counter > numEntry) {
                    entryInBlock[i] -= counter - numEntry;
                    counter = numEntry;
                }
            }
            // Use SBoost_old algorithm to compare the loaded block with spanned
            __m512i loaded = _mm512_setr_epi64(buffer[0], buffer[1], buffer[2], buffer[3],
                                               buffer[4], buffer[5], buffer[6], buffer[7]);
            __m512i l = _mm512_sub_epi64(_mm512_or_si512(loaded, msbmask), l2);
            __m512i r = _mm512_and_si512(_mm512_or_si512(loaded, nspanned),
                                         _mm512_or_si512(_mm512_and_si512(loaded, nspanned), l));

            // Use PEXT to collect result, use popcnt to count data
            for (int i = 0; i < 8; i++) {
                writeNext(res, _pext_u64(r[i], extract) & ((1L << entryInBlock[i]) - 1),
                          entryInBlock[i], &resindex, &resoffset);
            }
        }
    }

    uint32_t Bitpack::geq(const uint8_t *data, uint32_t numEntry) {
        uint64_t buffer[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entryInBlock[] = {0, 0, 0, 0, 0, 0, 0, 0};

        while (counter < numEntry) {
            // Load next block and align it
            for (int i = 0; i < 8; i++) {
                buffer[i] = loadNext(data, bitWidth, &byteindex, &bitoffset, entryInBlock + i);
            }
            // Use SBoost algorithm to compare the loaded block with spanned
            __m512i loaded = _mm512_setr_epi64(buffer[0], buffer[1], buffer[2], buffer[3],
                                               buffer[4], buffer[5], buffer[6], buffer[7]);
            __m512i l = _mm512_sub_epi64(_mm512_or_si512(loaded, msbmask), l2);
            __m512i r = _mm512_and_si512(_mm512_or_si512(loaded, nspanned),
                                         _mm512_or_si512(_mm512_and_si512(loaded, nspanned), l));

            // Use PEXT to collect result, use popcnt to count data

            for (int i = 0; i < 8; ++i) {
                auto res = _pext_u64(r[i], extract) & ((1L << entryInBlock[i]) - 1);
                if (res != 0) {
                    return counter + lowestBit(res);
                } else {
                    counter += entryInBlock[i];
                }
            }
            return -1;
        }
    }

    void Bitpack::greater(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset) {
        uint64_t buffer[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entryInBlock[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t resindex = resoffset >> 6;
        resoffset &= 0x3F;

        while (counter < numEntry) {
            // Load next block and align it
            for (int i = 0; i < 8; i++) {
                buffer[i] = loadNext(data, bitWidth, &byteindex, &bitoffset, entryInBlock + i);
                counter += entryInBlock[i];
                if (counter > numEntry) {
                    entryInBlock[i] -= counter - numEntry;
                    counter = numEntry;
                }
            }
            // Use SBoost_old algorithm to compare the loaded block with spanned
            __m512i loaded = _mm512_setr_epi64(buffer[0], buffer[1], buffer[2], buffer[3],
                                               buffer[4], buffer[5], buffer[6], buffer[7]);
            __m512i nloaded = _mm512_xor_si512(loaded, _mm512_set1_epi32(-1));
            __m512i l = _mm512_sub_epi64(g2, _mm512_and_si512(loaded, mask));
            __m512i r = _mm512_and_si512(_mm512_or_si512(nloaded, spanned),
                                         _mm512_or_si512(_mm512_and_si512(nloaded, spanned), l));

            // Use PEXT to collect result, use popcnt to count data
            for (int i = 0; i < 8; i++) {
                writeNext(res, ~_pext_u64(r[i], extract) & ((1L << entryInBlock[i]) - 1),
                          entryInBlock[i], &resindex, &resoffset);
            }
        }
    }

    void Bitpack::leq(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset) {
        uint64_t buffer[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entryInBlock[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t resindex = resoffset >> 6;
        resoffset &= 0x3F;

        while (counter < numEntry) {
            // Load next block and align it
            for (int i = 0; i < 8; i++) {
                buffer[i] = loadNext(data, bitWidth, &byteindex, &bitoffset, entryInBlock + i);
                counter += entryInBlock[i];
                if (counter > numEntry) {
                    entryInBlock[i] -= counter - numEntry;
                    counter = numEntry;
                }
            }
            // Use SBoost_old algorithm to compare the loaded block with spanned
            __m512i loaded = _mm512_setr_epi64(buffer[0], buffer[1], buffer[2], buffer[3],
                                               buffer[4], buffer[5], buffer[6], buffer[7]);
            __m512i nloaded = _mm512_xor_si512(loaded, _mm512_set1_epi32(-1));
            __m512i l = _mm512_sub_epi64(g2, _mm512_and_si512(loaded, mask));
            __m512i r = _mm512_and_si512(_mm512_or_si512(nloaded, spanned),
                                         _mm512_or_si512(_mm512_and_si512(nloaded, spanned), l));

            // Use PEXT to collect result, use popcnt to count data
            for (int i = 0; i < 8; i++) {
                writeNext(res, _pext_u64(r[i], extract) & ((1L << entryInBlock[i]) - 1),
                          entryInBlock[i], &resindex, &resoffset);
            }
        }
    }

    void Bitpack::rangele(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset) {
        uint64_t buffer[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entryInBlock[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t resindex = resoffset >> 6;
        resoffset &= 0x3F;

        while (counter < numEntry) {
            // Load next block and align it
            for (int i = 0; i < 8; i++) {
                buffer[i] = loadNext(data, bitWidth, &byteindex, &bitoffset, entryInBlock + i);
                counter += entryInBlock[i];
                if (counter > numEntry) {
                    entryInBlock[i] -= counter - numEntry;
                    counter = numEntry;
                }
            }
            // Use SBoost_old algorithm to compare the loaded block with spanned
            __m512i loaded = _mm512_setr_epi64(buffer[0], buffer[1], buffer[2], buffer[3],
                                               buffer[4], buffer[5], buffer[6], buffer[7]);
            __m512i ll = _mm512_sub_epi64(_mm512_or_si512(loaded, msbmask), l2);
            __m512i rl = _mm512_and_si512(_mm512_or_si512(loaded, nspanned),
                                          _mm512_or_si512(_mm512_and_si512(loaded, nspanned), ll));
            __m512i lu = _mm512_sub_epi64(_mm512_or_si512(loaded, msbmask), l22);
            __m512i ru = _mm512_and_si512(_mm512_or_si512(loaded, nspanned2),
                                          _mm512_or_si512(_mm512_and_si512(loaded, nspanned2), lu));

            __m512i r = _mm512_xor_si512(rl, ru);

            // Use PEXT to collect result, use popcnt to count data
            for (int i = 0; i < 8; i++) {
                writeNext(res, _pext_u64(r[i], extract) & ((1L << entryInBlock[i]) - 1),
                          entryInBlock[i], &resindex, &resoffset);
            }
        }
    }

    void Bitpack::between(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset) {
        uint64_t buffer[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entryInBlock[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t resindex = resoffset >> 6;
        resoffset &= 0x3F;

        while (counter < numEntry) {
            // Load next block and align it
            for (int i = 0; i < 8; i++) {
                buffer[i] = loadNext(data, bitWidth, &byteindex, &bitoffset, entryInBlock + i);
                counter += entryInBlock[i];
                if (counter > numEntry) {
                    entryInBlock[i] -= counter - numEntry;
                    counter = numEntry;
                }
            }
            // Use SBoost_old algorithm to compare the loaded block with spanned
            __m512i loaded = _mm512_setr_epi64(buffer[0], buffer[1], buffer[2], buffer[3],
                                               buffer[4], buffer[5], buffer[6], buffer[7]);
            __m512i ll = _mm512_sub_epi64(_mm512_or_si512(loaded, msbmask), l2);
            __m512i rl = _mm512_and_si512(_mm512_or_si512(loaded, nspanned),
                                          _mm512_or_si512(_mm512_and_si512(loaded, nspanned), ll));
            __m512i nloaded = _mm512_xor_si512(loaded, _mm512_set1_epi32(-1));
            __m512i lu = _mm512_sub_epi64(g22, _mm512_and_si512(loaded, mask));
            __m512i ru = _mm512_and_si512(_mm512_or_si512(nloaded, spanned2),
                                          _mm512_or_si512(_mm512_and_si512(nloaded, spanned2), lu));

            __m512i r = _mm512_and_si512(rl, ru);

            // Use PEXT to collect result, use popcnt to count data
            for (int i = 0; i < 8; i++) {
                writeNext(res, _pext_u64(r[i], extract) & ((1L << entryInBlock[i]) - 1),
                          entryInBlock[i], &resindex, &resoffset);
            }
        }
    }

    uint32_t estimateGroupSize(uint32_t bitWidth) {
        // Estimate group size
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entries = 0;
        for (int i = 0; i < 8; i++) {
            // Update index and offset
            auto entryInBlock = (64 - bitoffset) / bitWidth;
            uint32_t bitadvance = entryInBlock * bitWidth + (bitoffset);
            bitoffset = bitadvance & 0x7;
            byteindex += bitadvance >> 3;

            entries += entryInBlock;
        }
        return ((entries >> 3) << 3);
    }

    TemplateBitpack::TemplateBitpack(uint32_t bitWidth, uint32_t target) : Bitpack(bitWidth, target) {
        entry_in_blocks_ = loader::entryInBlocks[bitWidth];
        group_size_ = estimateGroupSize(bitWidth);
        group_bytes_ = (group_size_ * bitWidth) >> 3;
    }

    void TemplateBitpack::tgeq(const uint8_t *data, uint32_t numEntry, uint64_t *res, uint32_t resoffset) {
        uint64_t buffer[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;

        uint32_t resindex = resoffset >> 6;
        resoffset &= 0x3F;

        auto loader = loader::loaders[bitWidth];

        while (counter < numEntry) {
            // Load next block and align it
            loader(data, buffer);
            data += group_bytes_;
            counter += group_size_;
            if (counter > numEntry) {
                counter = numEntry;
            }

            // Use SBoost algorithm to compare the loaded block with spanned
            __m512i loaded = _mm512_setr_epi64(buffer[0], buffer[1], buffer[2], buffer[3],
                                               buffer[4], buffer[5], buffer[6], buffer[7]);
            __m512i l = _mm512_sub_epi64(_mm512_or_si512(loaded, msbmask), l2);
            __m512i r = _mm512_and_si512(_mm512_or_si512(loaded, nspanned),
                                         _mm512_or_si512(_mm512_and_si512(loaded, nspanned), l));

            // Use PEXT to collect result, use popcnt to count data
            for (int i = 0; i < 8; i++) {
                writeNext(res, _pext_u64(r[i], extract) & ((1L << entry_in_blocks_[i]) - 1),
                          entry_in_blocks_[i], &resindex, &resoffset);
            }
        }
    }

    SortedBitpack::SortedBitpack(uint32_t bitWidth, uint32_t target) : Bitpack(bitWidth, target) {
        loader_ = loader::loaders[bitWidth];
        writer_ = loader::writers[bitWidth];
        writerinv_ = loader::writeinvs[bitWidth];
        group_size_ = estimateGroupSize(bitWidth);

        entry_in_block_ = loader::entryInBlocks[bitWidth];

        group_bytes_ = (group_size_ * bitWidth) >> 3;

        last_index_ = (group_size_ - 1) >> 6;
        last_offset_ = ((group_size_ - 1) & 0x3F);
    }

    SortedBitpack::~SortedBitpack() noexcept {}

    int8_t SortedBitpack::eqGroup(const uint8_t *group_start, uint64_t *res) {
        loader_(group_start, buffer_);

        // Use SBoost algorithm to compare the loaded block with spanned
        __m512i loaded = _mm512_setr_epi64(buffer_[0], buffer_[1], buffer_[2], buffer_[3],
                                           buffer_[4], buffer_[5], buffer_[6], buffer_[7]);
        __m512i d = _mm512_xor_si512(loaded, spanned);
        __m512i r = _mm512_or_si512(d, _mm512_add_epi64(_mm512_and_si512(d, mask), mask));

        memset(res, 0, 64);
        writerinv_(r, res, extract);
        uint8_t index = 0;
        for (uint32_t i = 0; i <= last_index_; ++i) {
            if (res[i] != 0) {
                return index + _mm_popcnt_u64(res[i] - 1);
            } else {
                index += 64;
            }
        }
        return -1;
    }

    int8_t SortedBitpack::geqGroup(const uint8_t *group_start, uint64_t *res) {
        loader_(group_start, buffer_);

        // Use SBoost algorithm to compare the loaded block with spanned
        __m512i loaded = _mm512_setr_epi64(buffer_[0], buffer_[1], buffer_[2], buffer_[3],
                                           buffer_[4], buffer_[5], buffer_[6], buffer_[7]);
        __m512i l = _mm512_sub_epi64(_mm512_or_si512(loaded, msbmask), l2);
        __m512i r = _mm512_and_si512(_mm512_or_si512(loaded, nspanned),
                                     _mm512_or_si512(_mm512_and_si512(loaded, nspanned), l));

        memset(res, 0, 64);
        writer_(r, res, extract);

        auto first = res[0] & 1;
        auto last = (res[last_index_] >> last_offset_) & 1;
        if (first) {
            return 0;
        } else if (!last) {
            return -1;
        } else {
            uint32_t offset = 0;
            // Found between
            for (uint32_t i = 0; i <= last_index_; ++i) {
                if (res[i] == 0) {
                    offset += 64;
                } else {
                    offset += lowestBit(res[i]);
                    break;
                }
            }
            return offset;
        }
    }

    void SortedBitpack::geqGroup2(const uint8_t *group_start, uint64_t *res) {
        loader_(group_start, buffer_);

        // Use SBoost algorithm to compare the loaded block with spanned
        __m512i loaded = _mm512_setr_epi64(buffer_[0], buffer_[1], buffer_[2], buffer_[3],
                                           buffer_[4], buffer_[5], buffer_[6], buffer_[7]);
        __m512i l = _mm512_sub_epi64(_mm512_or_si512(loaded, msbmask), l2);
        __m512i r = _mm512_and_si512(_mm512_or_si512(loaded, nspanned),
                                     _mm512_or_si512(_mm512_and_si512(loaded, nspanned), l));

        uint32_t resindex = 0;
        uint32_t resoffset = 0;
        memset(res, 0, 64);
        for (int i = 0; i < 8; i++) {
            writeNext(res, _pext_u64(r[i], extract) & ((1L << entry_in_block_[i]) - 1),
                      entry_in_block_[i], &resindex, &resoffset);
        }
    }

    uint32_t SortedBitpack::equal(const uint8_t *data, uint32_t numEntry) {
        auto num_groups = (numEntry + 1) / group_size_;
        // Estimate group size

        uint64_t bitmap_result[8];

        uint32_t begin = 0;
        uint32_t end = num_groups - 1;
        while (begin != end) {
            auto current = (begin + end) / 2;
            const uint8_t *current_buffer = data + current * group_bytes_;
//            bitmap_result[bitmap_last_index] = -1;
            // Make comparison
            auto index = geqGroup(current_buffer, bitmap_result);
            if (index != -1) {
                end = current;
                auto eqindex = eqGroup(current_buffer, bitmap_result);
                if (eqindex != -1) {
                    return current * group_size_ + eqindex;
                }
            } else {
                // If all small
                begin = current;
            }
        }
        // No found in between, result on border
        return (uint32_t) -1;
    }

    uint32_t SortedBitpack::geq(const uint8_t *data, uint32_t numEntry) {
        auto num_groups = (numEntry + 1) / group_size_;
        // Estimate group size

        uint64_t bitmap_result[8];

        uint8_t compare_result[num_groups];
        memset(compare_result, 2, num_groups);

        uint32_t begin = 0;
        uint32_t end = num_groups - 1;
        while (begin < end) {
            auto current = (begin + end + 1) / 2;
            const uint8_t *current_buffer = data + current * group_bytes_;
//            bitmap_result[bitmap_last_index] = -1;
            // Make comparison
            auto index = geqGroup(current_buffer, bitmap_result);
            // If all large
            if (index == 0) {
                end = current;
                if (compare_result[current] == 2) {
                    compare_result[current] = 1;
                    if (current == 0) {
                        return 0;
                    }
                    if (compare_result[current - 1] == 0) {
                        return current * group_size_;
                    }
                } else {
                    break;
                }
            } else if (index == -1) {
                // all small
                begin = current;
                if (compare_result[current] == 2) {
                    compare_result[current] = 0;
                    if (current == num_groups - 1) {
                        return numEntry - 1;
                    }
                    if (compare_result[current + 1] == 1) {
                        return (current + 1) * group_size_;
                    }
                } else {
                    break;
                }
            } else {
                return current * group_size_ + index;
            }
        }
        // No found in between, result on border
        return (uint32_t) -1;
    }

    BitpackCompare::BitpackCompare(uint32_t bitWidth) {
        this->bit_width_ = bitWidth;
        this->extract_ = EXTRACT_64[bitWidth];
        this->mask_ = _mm512_set1_epi64(MASKS_64[bitWidth]);
        this->msbmask_ = _mm512_set1_epi64(EXTRACT_64[bitWidth]);
    }

    void BitpackCompare::less(const uint8_t *data1, const uint8_t *data2,
                              uint32_t numEntry, uint64_t *res, uint32_t resoffset) {
        uint64_t buffer1[] = {0, 0, 0, 0, 0, 0, 0, 0};
        uint64_t buffer2[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t counter = 0;
        uint32_t byteindex = 0;
        uint32_t bitoffset = 0;
        uint32_t entryInBlock[] = {0, 0, 0, 0, 0, 0, 0, 0};

        uint32_t resindex = resoffset >> 6;
        resoffset &= 0x3F;

        while (counter < numEntry) {
            // Load next block and align it
            for (int i = 0; i < 8; i++) {
                auto bytidx = byteindex;
                auto bitoff = bitoffset;
                buffer1[i] = loadNext(data1, bit_width_, &byteindex, &bitoffset, entryInBlock + i);
                buffer2[i] = loadNext(data2, bit_width_, &bytidx, &bitoff, entryInBlock + i);
                counter += entryInBlock[i];
                if (counter > numEntry) {
                    entryInBlock[i] -= counter - numEntry;
                    counter = numEntry;
                }
            }
            // Use SBoost algorithm to compare the loaded block
            __m512i loaded1 = _mm512_setr_epi64(buffer1[0], buffer1[1], buffer1[2], buffer1[3],
                                                buffer1[4], buffer1[5], buffer1[6], buffer1[7]);
            __m512i loaded2 = _mm512_setr_epi64(buffer2[0], buffer2[1], buffer2[2], buffer2[3],
                                                buffer2[4], buffer2[5], buffer2[6], buffer2[7]);

            __m512i spanned = loaded2;
            __m512i nspanned = _mm512_xor_si512(spanned, _mm512_set1_epi64(-1));
            __m512i l2 = _mm512_and_si512(spanned, mask_);
            __m512i g2 = _mm512_or_si512(spanned, msbmask_);

            __m512i l = _mm512_sub_epi64(_mm512_or_si512(loaded1, msbmask_), l2);
            __m512i r = _mm512_and_si512(_mm512_or_si512(loaded1, nspanned),
                                         _mm512_or_si512(_mm512_and_si512(loaded1, nspanned), l));

            // Use PEXT to collect result, use popcnt to count data
            for (int i = 0; i < 8; i++) {
                writeNext(res, ~_pext_u64(r[i], extract_) & ((1L << entryInBlock[i]) - 1),
                          entryInBlock[i], &resindex, &resoffset);
            }
        }
    }
}