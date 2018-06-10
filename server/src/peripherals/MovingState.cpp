//
// Created by marcin on 17.03.18.
//

#include "MovingState.h"
#include "OpenedState.h"
#include "ClosedState.h"
#include "IdleState.h"


void MovingState::blindsDown(Blinds &blinds)
{
    //TODO: Check if direction is contrary to actual and go to idle
    if(blinds.direction == Blinds::DIRECTION::UP)
    {
      blinds.blindsStop();
      setState(blinds, new IdleState());
    }
    else if(blinds.direction == Blinds::DIRECTION::STOPPED)
    {
        blinds.moveBlindsDown();
        setState(blinds, new MovingState());
    }
}

void MovingState::blindsUp(Blinds &blinds)
{
    //TODO: Check if direction is contrary to actual and go to idle
    if(blinds.direction == Blinds::DIRECTION::DOWN)
    {
      blinds.blindsStop();
      setState(blinds, new IdleState());
    }
    else if(blinds.direction == Blinds::DIRECTION::STOPPED)
    {
        blinds.moveBlindsUp();
        setState(blinds, new MovingState());
    }
}

void MovingState::blindsUpSwitch(Blinds &blinds)
{
    if(!blinds.topSwitch->pinRead())
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