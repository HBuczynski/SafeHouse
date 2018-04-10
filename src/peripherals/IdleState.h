//
// Created by marcin on 17.03.18.
//

#ifndef SAFEHOUSE_IDLESTATE_H
#define SAFEHOUSE_IDLESTATE_H


#include "AbstractState.h"

class IdleState: public AbstractState
{
public:
    virtual ~IdleState(){};

    virtual void blindsUp(Blinds& blinds);
    virtual void blindsDown(Blinds& blinds);

    virtual void blindsUpSwitch(Blinds& blinds);
    virtual void blindsDownSwitch(Blinds& blinds);

};


#endif //SAFEHOUSE_IDLESTATE_H
