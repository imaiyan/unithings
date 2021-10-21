//
// Created by enzor on 17/10/2021.
//

#ifndef REDES_M2_USER_H
#define REDES_M2_USER_H

#include <string>
#include <vector>
#include "rdt_segment_t.h"
#include "Observer.h"
#include "Sender.h"
#include "Receiver.h"

class User : public Observer<rdt_segment_t>
{

public:

    void sendMessage(std::queue<std::string> messageList, uint8_t dstPort);

    void init();

    explicit User(uint8_t receivePort, uint32_t ackTimeout) : receiver{receivePort}, sender(ackTimeout), port(receivePort) {};

    [[nodiscard]] uint8_t getPort() const;

private:

    void notify(rdt_segment_t packet) override;

    uint8_t port;

    RDT::Sender sender;
    RDT::Receiver receiver;

};


#endif //REDES_M2_USER_H
