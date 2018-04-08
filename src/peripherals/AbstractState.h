//
// Created by marcin on 17.03.18.
//

#ifndef SAFEHOUSE_ABSTRACTSTATE_H
#define SAFEHOUSE_ABSTRACTSTATE_H

#include "Blinds.h"


class AbstractState {
public:
    virtual ~AbstractState();

protected:
    virtual void setState(Blinds& blinds, AbstractState* state);
};


#endif //SAFEHOUSE_ABSTRACTSTATE_H
