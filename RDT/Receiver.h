//
// Created by enzor on 18/10/2021.
//

#ifndef REDES_RDT_RECEIVER_H
#define REDES_RDT_RECEIVER_H


#include <cstdint>
#include <thread>
#include "Subject.h"
#include "rdt_segment_t.h"
#include "ReceiverConnection.h"
#include "SenderConnection.h"

namespace RDT
{
    class Receiver : public Subject<rdt_segment_t>
    {
        uint8_t port;

        SenderConnection senderConnection;

        void listen(ReceiverConnection *receiverConnection);

        std::thread listener;

        void checkSequence(const rdt_segment_t& packet);

    public:
        explicit Receiver(uint8_t p_port) : port(p_port) {}

        void start();

    };
}
#endif //REDES_RDT_RECEIVER_H
