
#include "GPIO.h"


bool GPIO::init() const
{
    if(!gpioSetMode(pinNumber, pinMode))
    {
        return true;
    }
    return false;
}

bool GPIO::setMode(uint8_t pinNumber_, uint8_t pinMode_, uint8_t pushPullMode_)
{
    pinNumber = pinNumber_;
    pinMode = pinMode_;
    pushPullMode = pushPullMode_;
}

int GPIO::pinRead(int state)
{
    return gpioRead(pinNumber);
}

void GPIO::pinWrite(int state)
{
    gpioWrite(pinNumber, state);
};