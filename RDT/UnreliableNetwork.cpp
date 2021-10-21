//
// Created by enzor on 17/10/2021.
//

#include "UnreliableNetwork.h"

void UnreliableNetwork::transmit(rdt_segment_t packet)
{
    static uint8_t packetNumber = 0;
    //printf("Sending packet to %u from %u | packetNumber: %u\n", packet.dstPort, packet.srcPort, packetNumber);

    //todo

    if(packetNumber == 1)
    {
        //packet.checksum = 0;
        //packetQueue[packet.dstPort].push(packet);
    }
    else {
        packetQueue[packet.dstPort].push(packet);
    }
    packetNumber++;
}

void UnreliableNetwork::registerConnection(RDT::ReceiverConnection *receiverConnection)
{
    printf("\r\nRegistering connection %p at port %u...\r\n", receiverConnection, receiverConnection->getPort());
    connectionList[receiverConnection->getPort()] = receiverConnection;
}

UnreliableNetwork & UnreliableNetwork::instance()
{
    static UnreliableNetwork unreliableNetwork;
    return unreliableNetwork;
}

std::optional<rdt_segment_t> UnreliableNetwork::getPacketForPort(uint8_t port)
{
    if(packetQueue[port].empty())
        return std::nullopt;

    auto packetToReturn = packetQueue[port].front();
    packetQueue[port].pop();

    return packetToReturn;
}

void UnreliableNetwork::unregisterConnection(uint8_t port)
{
    printf("Unregistering port %u...\r\n", port);
    connectionList.erase(port);
}

bool UnreliableNetwork::checkPortAvailability(uint8_t port)
{
    return connectionList.count(port) == 0;
}
