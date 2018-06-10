#include "MotionSensor.h"

MotionSensor::MotionSensor(uint8_t deviceID_)
    : GPIO(deviceID_, GPIOType::MOTION_SENSOR)
{

}

MotionSensor::~MotionSensor()
{

}

bool MotionSensor::isTriggered() const
{
    return triggered;
}

void MotionSensor::setSensor(bool isTriggered)
{
    triggered = isTriggered;
}

bool MotionSensor::registerHandler(gpioISRFuncEx_t fun, const int &edge, const int &timeout,void *intData)
{
    if(!gpioSetISRFuncEx(pinNumber, edge, timeout,interruptHandler, intData))
    {
        std::cout << "ISR register correct." << std::endl;
        return true;
    }
    return false;
}