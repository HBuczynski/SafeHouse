//
// Created by marcin on 17.03.18.
//

#ifndef SAFEHOUSE_ERRORSTATE_H
#define SAFEHOUSE_ERRORSTATE_H


#include "AbstractState.h"

class ErrorState: public AbstractState
{
public:
    virtual ~ErrorState(){};

    virtual void blindsUp(Blinds& blinds);
    virtual void blindsDown(Blinds& blinds);

    virtual void blindsUpSwitch(Blinds& blinds);
    virtual void blindsDownSwitch(Blinds& blinds);

    bool isError(const Blinds& blinds) const;

};


#endif //SAFEHOUSE_ERRORSTATE_H
