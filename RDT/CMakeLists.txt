cmake_minimum_required(VERSION 3.17)
project(redes_RDT)

set(CMAKE_CXX_STANDARD 20)

add_executable(redes_RDT
        main.cpp
        Sender.cpp
        Sender.h
        Receiver.h
        Receiver.cpp
        UnreliableNetwork.h
        UnreliableNetwork.cpp
        INetwork.h
        Observer.h
        Subject.h
        rdt_segment_t.h
        User.h
        User.cpp SenderConnection.cpp SenderConnection.h ReceiverConnection.cpp ReceiverConnection.h Exceptions.h)