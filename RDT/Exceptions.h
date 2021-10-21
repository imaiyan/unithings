//
// Created by enzor on 19/10/2021.
//

#ifndef REDES_RDT_EXCEPTIONS_H
#define REDES_RDT_EXCEPTIONS_H

#include <ios>

namespace RDT
{
    struct InvalidAckException : public std::ios_base::failure
    {
        explicit InvalidAckException(const std::string& message) : std::ios_base::failure(message) {}
    };

    struct BadChecksumException : public std::ios_base::failure
    {
        explicit BadChecksumException(const std::string& message, uint8_t p_port) : std::ios_base::failure(message), packetSrcPort(p_port) {}

        uint8_t packetSrcPort;
    };

    struct NoAckReceivedException : public std::ios_base::failure
    {
        explicit NoAckReceivedException(const std::string& message) : std::ios_base::failure(message) {}
    };

    struct InvalidSequenceException : public std::ios_base::failure
    {
        explicit InvalidSequenceException(const std::string& message, uint8_t p_port, uint8_t p_seq) : std::ios_base::failure(message), packetSrcPort(p_port), packetSequence(p_seq) {}

        uint8_t packetSrcPort;

        uint8_t packetSequence;
    };
}



#endif //REDES_RDT_EXCEPTIONS_H
