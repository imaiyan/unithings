//
// Created by enzor on 18/10/2021.
//

#include "SenderConnection.h"
#include "UnreliableNetwork.h"
#include "Exceptions.h"

void RDT::SenderConnection::send_packet(const std::string &message, uint8_t dstPort)
{
    rdt_segment_t packet{};

    packet.sequence = sequence;
    packet.ack = 0;
    packet.srcPort = srcPort;
    packet.dstPort = dstPort;

    for (int i = 0; i < message.size(); i++) {
        packet.payload[i] = message[i];
    }

    packet.checksum = checksum(packet);

    UnreliableNetwork::instance().transmit(packet);
}

uint8_t RDT::SenderConnection::checksum(rdt_segment_t packet)
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

void RDT::SenderConnection::treatAck(rdt_segment_t packet)
{
    if(packet.sequence != sequence)
        throw RDT::InvalidAckException("Invalid ack exception");

    sequence = !sequence;
}

void RDT::SenderConnection::send_ack(uint8_t dstPort)
{
    rdt_segment_t packet{};

    packet.sequence = sequence;
    packet.ack = 1;
    packet.srcPort = srcPort;
    packet.dstPort = dstPort;

    packet.checksum = checksum(packet);

    UnreliableNetwork::instance().transmit(packet);
    sequence = !sequence;
}

void RDT::SenderConnection::send_nack(uint8_t dstPort)
{
    rdt_segment_t packet{};

    packet.sequence = !sequence;
    packet.ack = 1;
    packet.srcPort = srcPort;
    packet.dstPort = dstPort;

    packet.checksum = checksum(packet);

    UnreliableNetwork::instance().transmit(packet);
    sequence = !sequence;
}

RDT::SenderConnection::SenderConnection() : sequence(0)
{
    uint8_t p_srcPort = rand();

    while(!UnreliableNetwork::instance().checkPortAvailability(srcPort))
    {
        srcPort = rand();
    }

    srcPort = p_srcPort;
}

RDT::SenderConnection::SenderConnection(uint8_t p_seq) : sequence(p_seq)
{
    uint8_t p_srcPort = rand();

    while(!UnreliableNetwork::instance().checkPortAvailability(srcPort))
    {
        srcPort = rand();
    }

    srcPort = p_srcPort;
}

uint8_t RDT::SenderConnection::getPort() const
{
    return srcPort;
}

uint8_t RDT::SenderConnection::getSequence() const
{
    return sequence;
}

void RDT::SenderConnection::send_ack(uint8_t dstPort, uint8_t seq)
{
    rdt_segment_t packet{};

    packet.sequence = seq;
    packet.ack = 1;
    packet.srcPort = srcPort;
    packet.dstPort = dstPort;

    packet.checksum = checksum(packet);

    UnreliableNetwork::instance().transmit(packet);
}
