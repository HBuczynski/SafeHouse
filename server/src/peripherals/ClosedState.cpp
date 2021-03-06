//
// Created by marcin on 17.03.18.
//

#include <iostream>

#include "ClosedState.h"
#include "MovingState.h"
#include "ErrorState.h"

void ClosedState::blindsDown(Blinds &blinds)
{
    if(blinds.logger.isInformationEnable())
    {
        const std::string message = std::string("Blinds already down!");
        blinds.logger.writeLog(utility::LogType::INFORMATION_LOG, message);
    }
}

void ClosedState::blindsUp(Blinds &blinds)
{
    blinds.moveBlindsUp();
    setState(blinds, new MovingState());
}

void ClosedState::blindsUpSwitch(Blinds &blinds)
{
    if(!blinds.topSwitch->pinRead())
    {
        blinds.blindsStop();
        setState(blinds, new ErrorState());
    }
}

void ClosedState::blindsDownSwitch(Blinds &blinds)
{
    if(blinds.bottomSwitch->pinRead())
    {
        blinds.blindsStop();
        setState(blinds, new ErrorState());
    }

}