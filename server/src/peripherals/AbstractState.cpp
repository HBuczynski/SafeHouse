#include "AbstractState.h"

#include <peripherals/PeriphManager.h>

using namespace peripherials;

AbstractState::AbstractState()
	:stateName("AbstractState"),
	periphManager(PeriphManager::getInstance())
{
	
};

void AbstractState::setState(Blinds& blinds, AbstractState* state)
{
    blinds.actualState.reset(state);
		
    if(blinds.logger.isInformationEnable())
    {
        const std::string message = std::string("Changing state to: " + blinds.actualState->stateName);
        blinds.logger.writeLog(utility::LogType::INFORMATION_LOG, message);
    }
	
	periphManager.runBlindsStatus();
}