
#include "Motor.h"


bool Motor::init() const
{
    if(!gpioSetPWMfrequency(pinNumber,pwmFrequency))
    {
        return true;
    }
    return false;
}

bool Motor::setRange(const int &pwmUpperRange_) const
{
    if(!gpioSetPWMrange(pinNumber, pwmUpperRange_))
        return true;
    return false;
}

int Motor::getRange() const
{
    return gpioGetPWMrange(pinNumber);
}

bool Motor::setPWM(unsigned int &pwmValue_)
{
    if(pwmValue_ > static_cast<unsigned int>(getRange()))
        pwmValue_ = getRange();
    if(!gpioPWM(pinNumber, pwmValue_))
    {
        return true;
    }
    return false;
}

bool Motor::setPWMFrequency(const int &frequency)
{
    if(!gpioSetPWMfrequency(pinNumber,frequency))
    {
        pwmFrequency = frequency;
        return true;
    }
    return false;
};

