#include "GPIO.h"

GPIO::GPIO(uint8_t deviceId_, GPIOType type_)
    : deviceId(deviceId_),
      deviceType(type_)
{ }

bool GPIO::init() const
{
    if(!gpioSetMode(pinNumber, pinMode) && !gpioSetPullUpDown(pinNumber, pushPullMode))
    {
        return true;
    }
    return false;
}

void GPIO::setMode(uint8_t pinNumber_, uint8_t pinMode_, uint8_t pushPullMode_)
{
    pinNumber = pinNumber_;
    pinMode = pinMode_;
    pushPullMode = pushPullMode_;
}

int GPIO::pinRead() const
{
    return gpioRead(pinNumber);
}

void GPIO::pinWrite(int state)
{
    gpioWrite(pinNumber, state);
}
