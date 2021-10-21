//
// Created by enzor on 17/10/2021.
//

#ifndef REDES_M2_INETWORK_H
#define REDES_M2_INETWORK_H

#include "rdt_segment_t.h"

struct INetwork
{
    virtual void transmit(rdt_segment_t packet) = 0;
};

#endif //REDES_M2_INETWORK_H

