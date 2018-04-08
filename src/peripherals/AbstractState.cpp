//
// Created by marcin on 17.03.18.
//

#include "AbstractState.h"


void AbstractState::setState(Blinds& blinds, AbstractState* state)
{
    blinds.actualState.reset(state);
}