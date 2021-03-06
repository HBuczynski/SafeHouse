//
// Created by marcin on 17.03.18.
//

#ifndef SAFEHOUSE_MOVINGSTATE_H
#define SAFEHOUSE_MOVINGSTATE_H


#include "AbstractState.h"

class MovingState: public AbstractState
{
public:
    MovingState():AbstractState(){
        stateName = "MovingState";
    };
    virtual ~MovingState(){};

    virtual void blindsUp(Blinds& blinds);
    virtual void blindsDown(Blinds& blinds);

    virtual void blindsUpSwitch(Blinds& blinds);
    virtual void blindsDownSwitch(Blinds& blinds);

};


#endif //SAFEHOUSE_MOVINGSTATE_H
