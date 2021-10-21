//
// Created by enzor on 18/10/2021.
//

#ifndef REDES_RDT_SENDERCONNECTION_H
#define REDES_RDT_SENDERCONNECTION_H

#include <string>
#include "rdt_segment_t.h"

namespace RDT
{
    class SenderConnection
    {
        uint8_t sequence;

        uint8_t checksum(rdt_segment_t packet);

        uint8_t srcPort;

    public:
        void send_packet(const std::string& message, uint8_t dstPort);

        void send_ack(uint8_t dstPort);

        void send_ack(uint8_t dstPort, uint8_t seq);

        void send_nack(uint8_t dstPort);


        void treatAck(rdt_segment_t packet);

        [[nodiscard]] uint8_t getPort() const;

        [[nodiscard]] uint8_t getSequence() const;

        SenderConnection();

        explicit SenderConnection(uint8_t p_seq);
    };
}
#endif //REDES_RDT_SENDERCONNECTION_H
