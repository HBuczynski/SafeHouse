//
// Created by marcin on 17.03.18.
//

#include <iostream>

#include "OpenedState.h"
#include "MovingState.h"
#include "ErrorState.h"


void OpenedState::blindsDown(Blinds &blinds)
{
    blinds.moveBlindsDown();
    setState(blinds, new MovingState());
}

void OpenedState::blindsUp(Blinds &blinds)
{
    std::cout << "Blinds already up!";
}

void OpenedState::blindsUpSwitch(Blinds &blinds)
{
    if(blinds.bottomSwitch->pinRead())
    {
        blinds.blindsStop();
        setState(blinds, new ErrorState());
    }
}

void OpenedState::blindsDownSwitch(Blinds &blinds)
{
    if(!blinds.topSwitch->pinRead())
    {
        blinds.blindsStop();
        setState(blinds, new ErrorState());
    }

}