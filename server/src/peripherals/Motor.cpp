
#include "Motor.h"


bool Motor::init() const
{
    if(!gpioSetPWMfrequency(PWMLeftPin,pwmFrequency) && !gpioSetPWMfrequency(PWMRightPin,pwmFrequency))
    {
        return true;
    }
    return false;
}

bool Motor::setRange(const int &pwmUpperRange_) const
{
    if(!gpioSetPWMrange(PWMLeftPin, pwmUpperRange_) && !gpioSetPWMrange(PWMRightPin, pwmUpperRange_))
        return true;
    return false;
}

int Motor::getRange() const
{
    return gpioGetPWMrange(PWMLeftPin);
}

bool Motor::setPWM(unsigned int pwmValue_, uint8_t pinNumber)
{
    if(pwmValue_ > static_cast<unsigned int>(getRange()))
        pwmValue_ = getRange();
    if(!gpioPWM(pinNumber, pwmValue_))
    {
        return true;
    }
    return false;
}

bool Motor::setMotorPins(uint8_t leftPWM, uint8_t rightPWM, uint8_t enable)
{
    PWMLeftPin = leftPWM;
    PWMRightPin = rightPWM;
    enablePin = enable;
    if(gpioSetMode(enablePin, PI_OUTPUT) || gpioSetPullUpDown(enablePin, PI_PUD_OFF))
    {
        return false;
    }

    if(gpioSetMode(PWMRightPin, PI_OUTPUT) || gpioSetPullUpDown(PWMRightPin, PI_PUD_OFF))
    {
        return false;
    }

    if(gpioSetMode(PWMLeftPin, PI_OUTPUT) || gpioSetPullUpDown(PWMLeftPin, PI_PUD_OFF))
    {
        return false;
    }
    gpioWrite(enablePin, PI_HIGH);
    return true;
}

bool Motor::setPWMFrequency(const int frequency, uint8_t pinNumber)
{
    if(!gpioSetPWMfrequency(pinNumber,frequency))
    {
        pwmFrequency = frequency;
        return true;
    }
    return false;
};

