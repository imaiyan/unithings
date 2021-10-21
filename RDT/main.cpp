#include <iostream>
#include "User.h"
#include "UnreliableNetwork.h"

int main()
{

    using MessageQueue = std::queue<std::string>;
    constexpr uint32_t ACK_TIMEOUT = 300;

    User alice(1, ACK_TIMEOUT);
    User bob(2, ACK_TIMEOUT);

    alice.init();
    bob.init();

    MessageQueue alice_messageQueue, bob_messageQueue, alice_messageQueue2;
    alice_messageQueue.push("oi");
    bob_messageQueue.push("oi!");
    bob_messageQueue.push("tudo bem?");
    alice_messageQueue2.push("tudo certo");
    alice_messageQueue2.push("e ai?");

    alice.sendMessage(alice_messageQueue, bob.getPort());
    bob.sendMessage(bob_messageQueue, alice.getPort());
    alice.sendMessage(alice_messageQueue2, bob.getPort());



    for(;;) {}
    return 0;
}
