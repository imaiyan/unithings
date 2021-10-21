//
// Created by enzor on 18/10/2021.
//

#include "Sender.h"
#include "Exceptions.h"

void RDT::Sender::send_message(std::queue<std::string> messageList, uint8_t dstPort)
{


    ReceiverConnection receiverConnection(senderConnection.getPort());

    receiverConnection.start();

    printf("Connection established at port %u with port %u\n",receiverConnection.getPort(), dstPort);

    while(!messageList.empty())
        while (true)
        {
            senderConnection.send_packet(messageList.front(), dstPort);
            try
            {
                rdt_segment_t packet{};

                packet = receiverConnection.receivePackage(300);
                senderConnection.treatAck(packet);
                messageList.pop();
            }
            catch (RDT::BadChecksumException &exception)
            {
                printf(exception.what());
                continue;
            }
            catch (RDT::InvalidAckException &exception)
            {
                printf(exception.what());
                continue;
            }
            catch (RDT::NoAckReceivedException &exception)
            {
                printf(exception.what());
                continue;
            }
            break;
        }
}