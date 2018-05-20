//
// Created by marcin on 17.03.18.
//

#include <iostream>

#include "ErrorState.h"
#include "ClosedState.h"
#include "MovingState.h"
#include "OpenedState.h"


void ErrorState::blindsDown(Blinds &blinds)
{
    if(isError(blinds))
    {
        if(blinds.logger.isInformationEnable())
        {
            const std::string message = std::string("Error! Possible hardware malfunction.");
            blinds.logger.writeLog(utility::LogType::INFORMATION_LOG, message);
        }
        return;
    }
    else if(!blinds.bottomSwitch->pinRead())
    {
        if(blinds.logger.isInformationEnable())
        {
            const std::string message = std::string("Blinds already down.");
            blinds.logger.writeLog(utility::LogType::INFORMATION_LOG, message);
        }
        setState(blinds, new ClosedState());
    }
    else
    {
        blinds.moveBlindsDown();
        setState(blinds, new MovingState());
    }
}

void ErrorState::blindsUp(Blinds &blinds)
{
    if(isError(blinds))
    {
        if(blinds.logger.isInformationEnable())
        {
            const std::string message = std::string("Error! Possible hardware malfunction.");
            blinds.logger.writeLog(utility::LogType::INFORMATION_LOG, message);
        }
        return;
    }
    else if(!blinds.topSwitch->pinRead())
    {
        if(blinds.logger.isInformationEnable())
        {
            const std::string message = std::string("Blinds already up.");
            blinds.logger.writeLog(utility::LogType::INFORMATION_LOG, message);
        }
        setState(blinds, new OpenedState());
    }
    else
    {
        blinds.moveBlindsUp();
        setState(blinds, new MovingState());
    }
}

void ErrorState::blindsUpSwitch(Blinds &blinds)
{
    if(isError(blinds))
    {
        if(blinds.logger.isInformationEnable())
        {
            const std::string message = std::string("Error! Possible hardware malfunction.");
            blinds.logger.writeLog(utility::LogType::INFORMATION_LOG, message);
        }
        return;
    }
    else if(!blinds.topSwitch->pinRead())
    {
        setState(blinds, new OpenedState());
    }
}

void ErrorState::blindsDownSwitch(Blinds &blinds)
{
    if(isError(blinds))
    {
        if(blinds.logger.isInformationEnable())
        {
            const std::string message = std::string("Error! Possible hardware malfunction.");
            blinds.logger.writeLog(utility::LogType::INFORMATION_LOG, message);
        }
        return;
    }
    else if(!blinds.bottomSwitch->pinRead())
    {
        setState(blinds, new ClosedState());
    }
}

bool ErrorState::isError(const Blinds& blinds) const
{
    if(!blinds.bottomSwitch->pinRead() && !blinds.topSwitch->pinRead())
    {
        return true;
    }
    return false;
}