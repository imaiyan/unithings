//
// Created by enzor on 17/10/2021.
//

#ifndef REDES_M2_UNRELIABLENETWORK_H
#define REDES_M2_UNRELIABLENETWORK_H


#include <map>
#include <memory>
#include <queue>
#include <optional>
#include "INetwork.h"
#include "ReceiverConnection.h"

class UnreliableNetwork : public INetwork
{
public:
    void transmit(rdt_segment_t packet) override;

    void registerConnection(RDT::ReceiverConnection *receiverConnection);

    static UnreliableNetwork & instance();

    std::optional<rdt_segment_t> getPacketForPort(uint8_t port);

    void unregisterConnection(uint8_t port);

    bool checkPortAvailability(uint8_t port);

private:

    UnreliableNetwork() = default;

    using Port = uint8_t;

    std::map<Port, RDT::ReceiverConnection*> connectionList;

    std::map<Port, std::queue<rdt_segment_t>> packetQueue;

};


#endif //REDES_M2_UNRELIABLENETWORK_H
