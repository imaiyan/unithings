//
// Created by enzor on 18/10/2021.
//

#include "ReceiverConnection.h"
#include "UnreliableNetwork.h"
#include "Exceptions.h"
#include <chrono>

rdt_segment_t RDT::ReceiverConnection::receivePackage(uint32_t timeout) const
{
    auto startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    for(;;)
    {
        if(const auto optionalPacket = UnreliableNetwork::instance().getPacketForPort(port))
        {
            const auto& packet = optionalPacket.value();

            auto cksum = checksum(packet);
            if(cksum != packet.checksum)
                throw RDT::BadChecksumException("Bad checksum exception", packet.srcPort);

            else
                return packet;
        }
        auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        if((currentTime - startTime) > timeout)
            throw NoAckReceivedException("Ack timeout exception");
    }
}


uint8_t RDT::ReceiverConnection::checksum(rdt_segment_t packet) const
{
    uint8_t checksum = 0;

    checksum += packet.sequence;
    checksum += packet.ack;
    checksum += packet.srcPort;
    checksum += packet.dstPort;

    for(unsigned char byte : packet.payload)
        checksum += byte;

    return checksum;
}

void RDT::ReceiverConnection::start()
{
    UnreliableNetwork::instance().registerConnection(this);
}

uint8_t RDT::ReceiverConnection::getPort() const
{
    return port;
}

RDT::ReceiverConnection::~ReceiverConnection()
{
    UnreliableNetwork::instance().unregisterConnection(port);
}
