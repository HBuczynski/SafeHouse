#ifndef SAFEHOUSE_MOTIONSENSOR_H
#define SAFEHOUSE_MOTIONSENSOR_H

#include "GPIO.h"

class MotionSensor : public GPIO
{
public:
    MotionSensor(uint8_t deviceID_);
    ~MotionSensor();

    bool registerHandler(gpioISRFuncEx_t fun, const int &edge, const int &timeout,void *intData);

    bool isTriggered() const;
    void setSensor(bool isTriggered);

private:

    bool triggered = false;

};


#endif //SAFEHOUSE_MOTIONSENSOR_H
