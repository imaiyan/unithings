//
// Created by enzor on 17/10/2021.
//

#include "User.h"
#include "Exceptions.h"

void User::sendMessage(std::queue<std::string> messageList, uint8_t dstPort)
{
    sender.send_message({std::move(messageList)}, dstPort);
}

void User::notify(rdt_segment_t packet)
{
    printf("To %u: ", packet.dstPort);

    for(const auto& byte : packet.payload)
    {
        if(byte == '\0')
            break;

        printf("%c", byte);
    }

    printf("\r\n");
}

void User::init()
{
    receiver.register_observer(*this);
    receiver.start();
}

uint8_t User::getPort() const
{
    return port;
}
