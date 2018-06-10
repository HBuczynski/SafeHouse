//
// Created by marcin on 17.03.18.
//

#ifndef SAFEHOUSE_OPENEDSTATE_H
#define SAFEHOUSE_OPENEDSTATE_H


#include "AbstractState.h"

class OpenedState: public AbstractState
{
public:
    OpenedState():AbstractState(){
        stateName = "OpenedState";
    };
    virtual ~OpenedState(){};

    virtual void blindsUp(Blinds& blinds);
    virtual void blindsDown(Blinds& blinds);

    virtual void blindsUpSwitch(Blinds& blinds);
    virtual void blindsDownSwitch(Blinds& blinds);
};


#endif //SAFEHOUSE_OPENEDSTATE_H
