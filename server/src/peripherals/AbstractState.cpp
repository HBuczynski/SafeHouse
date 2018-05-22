//
// Created by marcin on 17.03.18.
//

#include "AbstractState.h"


void AbstractState::setState(Blinds& blinds, AbstractState* state)
{
    blinds.actualState.reset(state);
    if(blinds.logger.isInformationEnable())
    {
        const std::string message = std::string("Changing state to: " + blinds.actualState->stateName);
        blinds.logger.writeLog(utility::LogType::INFORMATION_LOG, message);
    }
}