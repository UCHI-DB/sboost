//
// Created by harper on 9/14/19.
//

#ifndef SBOOST_ENCODING_RLEHYBRID_H
#define SBOOST_ENCODING_RLEHYBRID_H

#include <cstdint>

namespace sboost {
    namespace encoding {
        namespace rlehybrid {

            typedef enum {
                RLE, PACKED
            } MODE;

            void equal(const uint8_t *, uint64_t *, uint32_t, uint32_t, uint32_t, uint32_t);

            void less(const uint8_t *, uint64_t *, uint32_t, uint32_t, uint32_t, uint32_t);

            void greater(const uint8_t *, uint64_t *, uint32_t, uint32_t, uint32_t, uint32_t);

            void between(const uint8_t *, uint64_t *, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

            void rangele(const uint8_t *, uint64_t *, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

            // Representing one segment
            struct Segment {
                MODE mode_;
                uint32_t num_entry_;
                const uint8_t *data_;
                int32_t data_length_;
                int32_t value_;
            };

            class SegmentReader {
            protected:
                const uint8_t *data_;
                uint32_t bit_width_;
                uint32_t num_entry_;
                uint32_t pointer_;
                uint32_t counter_;
            public:
                SegmentReader(const uint8_t *, uint32_t, uint32_t);

                virtual ~SegmentReader() = default;

                bool hasNext();

                Segment next();
            };
        }
    }
}
#endif //SBOOST_ENCODING_RLEHYBRID_H
