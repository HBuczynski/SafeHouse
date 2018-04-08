//
// Created by marcin on 17.03.18.
//

#ifndef SAFEHOUSE_CLOSEDSTATE_H
#define SAFEHOUSE_CLOSEDSTATE_H


#include "AbstractState.h"

class ClosedState: public AbstractState
{
public:
    virtual ~ClosedState() = default;

    virtual void blindsUp(Blinds& blinds);
    virtual void blindsDown(Blinds& blinds);
};


#endif //SAFEHOUSE_CLOSEDSTATE_H
