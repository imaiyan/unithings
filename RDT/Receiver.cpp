//
// Created by enzor on 18/10/2021.
//

#include <thread>
#include "Receiver.h"
#include "SenderConnection.h"
#include "Exceptions.h"

void RDT::Receiver::start()
{
    auto* rConnection = new ReceiverConnection(port);
    rConnection->start();
    listener = std::thread(&RDT::Receiver::listen, this, rConnection);

}

void RDT::Receiver::listen(ReceiverConnection *receiverConnection)
{
    for(;;)
    {
        rdt_segment_t packet{};
        try
        {
            packet = receiverConnection->receivePackage();
            checkSequence(packet);

            notify_observers(packet);

            printf("[ACK] Sequence %u\r\n", packet.sequence);
            senderConnection.send_ack(packet.srcPort);
        }
        catch (BadChecksumException& exception)
        {
            printf(exception.what());
            printf("\n[NACK] Bad checksum\n");
            //senderConnection.send_nack(packet.srcPort);

        }
        catch (InvalidSequenceException& exception)
        {
            printf(exception.what());
            printf("\n[ACK] Sequence %u\n", exception.packetSequence);
            senderConnection.send_ack(packet.srcPort, exception.packetSequence);
        }

    }
}

void RDT::Receiver::checkSequence(const rdt_segment_t &packet)
{
    if (packet.sequence != senderConnection.getSequence())
    {
        printf("\n[Receiver SEQERROR] Expected %u, received %u\n", senderConnection.getSequence(), packet.sequence);
        throw InvalidSequenceException("Invalid sequence exception", packet.srcPort, packet.sequence);
    }
}
