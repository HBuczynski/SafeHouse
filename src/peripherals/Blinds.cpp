
#include "Blinds.h"


Blinds::Blinds(uint8_t blindsId_)
    : blindsId(blindsId_)
{
    motor = std::make_unique<Motor>();
    topSwitch = std::make_unique<Switch>();
    bottomSwitch = std::make_unique<Switch>();
    actualState = std::make_unique<IdleState>();
}

bool Blinds::init(uint16_t motorPin_, uint16_t topSwitchPin_, uint16_t bottomSwitchPin_) const
{
    motor->setMode(motorPin_, PI_OUTPUT, PI_PUD_OFF);
    topSwitch->setMode(topSwitchPin_, PI_OUTPUT, PI_PUD_OFF);
    bottomSwitch->setMode(bottomSwitchPin_, PI_OUTPUT, PI_PUD_OFF);

    if(motor->init())// && topSwitch->registerHandler() && bottomSwitch->registerHandler())
    {
        return true;
    }
    return false;
}

int Blinds::blindsUpCallback(int gpio, int level, uint32_t tick, void *userdata){return 0;};
int Blinds::blindsDownCallback(int gpio, int level, uint32_t tick, void *userdata){return 0;};

