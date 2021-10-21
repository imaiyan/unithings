//
// Created by enzor on 18/10/2021.
//

#ifndef REDES_RDT_RECEIVERCONNECTION_H
#define REDES_RDT_RECEIVERCONNECTION_H


#include <cstdint>
#include <functional>
#include "rdt_segment_t.h"

namespace RDT
{
    class ReceiverConnection
    {

        uint8_t port;

        [[nodiscard]] uint8_t checksum(rdt_segment_t packet) const;

    public:
        explicit ReceiverConnection(uint8_t p_port) : port(p_port)
        {}

        ~ReceiverConnection();

        void start();

        [[nodiscard]] rdt_segment_t receivePackage(uint32_t timeout = UINT32_MAX) const;

        [[nodiscard]] uint8_t getPort() const;
    };
}

#endif //REDES_RDT_RECEIVERCONNECTION_H
