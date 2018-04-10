//
// Created by marcin on 17.03.18.
//

#include <iostream>

#include "IdleState.h"
#include "MovingState.h"
#include "ErrorState.h"


void IdleState::blindsDown(Blinds &blinds)
{
    if(!(blinds.topSwitch->pinRead() && blinds.bottomSwitch->pinRead()))
    {
        blinds.moveBlindsDown();
        setState(blinds, new MovingState());
    }
    else
    {
        setState(blinds, new ErrorState());
    }
}

void IdleState::blindsUp(Blinds &blinds)
{
    blinds.moveBlindsUp();
    setState(blinds, new MovingState());
}

void IdleState::blindsUpSwitch(Blinds &blinds)
{
    if(blinds.topSwitch->pinRead() || blinds.bottomSwitch->pinRead())
    {
        setState(blinds, new ErrorState());
    }
}

void IdleState::blindsDownSwitch(Blinds &blinds)
{
    blindsUpSwitch(blinds);
}