//
// Created by enzor on 17/10/2021.
//

#ifndef REDES_M2_RDT_SEGMENT_T_H
#define REDES_M2_RDT_SEGMENT_T_H

#include <array>

struct rdt_segment_t
{
    uint8_t srcPort;
    uint8_t dstPort;
    uint8_t sequence;
    uint8_t ack;
    uint8_t checksum;
    std::array<uint8_t, 150> payload;
};

#endif //REDES_M2_RDT_SEGMENT_T_H
