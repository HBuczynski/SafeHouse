#ifndef SAFEHOUSE_MOTIONSENSOR_H
#define SAFEHOUSE_MOTIONSENSOR_H

#include "GPIO.h"

class MotionSensor : public GPIO
{
public:
    MotionSensor(uint8_t deviceID_);
    ~MotionSensor();

private:

};


#endif //SAFEHOUSE_MOTIONSENSOR_H
