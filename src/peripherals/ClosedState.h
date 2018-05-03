//
// Created by marcin on 17.03.18.
//

#ifndef SAFEHOUSE_CLOSEDSTATE_H
#define SAFEHOUSE_CLOSEDSTATE_H

#include "AbstractState.h"

//Class defining behaviour of blinds while closed (lower button ON, upper OFF, motor stopped)

class AbstractState;

class ClosedState: public AbstractState
{
public:
    virtual ~ClosedState(){};

    virtual void blindsUp(Blinds& blinds);
    virtual void blindsDown(Blinds& blinds);

    virtual void blindsUpSwitch(Blinds& blinds);
    virtual void blindsDownSwitch(Blinds& blinds);

    const std::string stateName = "Closed state";
};


#endif //SAFEHOUSE_CLOSEDSTATE_H
