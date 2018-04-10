//
// Created by marcin on 17.03.18.
//

#include "MovingState.h"
#include "OpenedState.h"
#include "ClosedState.h"


void MovingState::blindsDown(Blinds &blinds)
{
    /*TODO: Check if direction is contrary to actual and go to idle
    if(direction != down)
    {
      blinds.blindsStop();
      setState(blinds, new IdleState());
    }*/
}

void MovingState::blindsUp(Blinds &blinds)
{
    /*TODO: Check if direction is contrary to actual and go to idle
    if(direction != up)
    {
        blinds.blindsStop();
        setState(blinds, new IdleState());
    }*/
}

void MovingState::blindsUpSwitch(Blinds &blinds)
{
    if(blinds.topSwitch->pinRead())
    {
        blinds.blindsStop();
        setState(blinds, new OpenedState());
    }
}

void MovingState::blindsDownSwitch(Blinds &blinds)
{
    if(!blinds.bottomSwitch->pinRead())
    {
        blinds.blindsStop();
        setState(blinds, new ClosedState());
    }

}