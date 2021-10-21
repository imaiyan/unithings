//
// Created by enzor on 18/10/2021.
//

#ifndef REDES_RDT_SENDER_H
#define REDES_RDT_SENDER_H

#include <queue>
#include "SenderConnection.h"
#include "ReceiverConnection.h"

namespace RDT
{
    class Sender
    {

        uint32_t ackTimeout;

        SenderConnection senderConnection;

    public:
        void send_message(std::queue<std::string> messageList, uint8_t dstPort);

        explicit Sender(uint32_t p_ackTimeout) : ackTimeout(p_ackTimeout) {}
    };
}

#endif //REDES_RDT_SENDER_H
