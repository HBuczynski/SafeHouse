//
// Created by marcin on 11.03.18.
//

#include "Blinds.h"


Blinds::Blinds(uint8_t deviceId_): GPIO(deviceId_)
{
    motor = make_unique<Motor>();
    topSwitch = make_unique<Switch>();
    bottomSwitch = make_unique<Switch>();
}

bool Blinds::init(uint16_t motorPin_, uint16_t topSwitchPin_, uint16_t bottomSwitchPin_) const
{
    motor->setMode(motorPin_, PI_OUTPUT, PI_PUD_OFF);
    topSwitch->setMode(topSwitchPin_, PI_OUTPUT, PI_PUD_OFF);
    bottomSwitch->setMode(bottomSwitchPin_, PI_OUTPUT, PI_PUD_OFF);

    if(motor->init() && topSwitch->init() && bottomSwitch->init())
    {
        return true;
    }
    return false;

}

