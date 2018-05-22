#include "MotionSensor.h"

MotionSensor::MotionSensor(uint8_t deviceID_)
    : GPIO(deviceID_, GPIOType::MOTION_SENSOR)
{

}

MotionSensor::~MotionSensor()
{

}
