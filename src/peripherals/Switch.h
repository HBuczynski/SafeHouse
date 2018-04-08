
#ifndef SAFEHOUSE_SWITCH_H
#define SAFEHOUSE_SWITCH_H

#include "GPIO.h"

class Switch: public GPIO
{
public:
    Switch() = default;
    Switch(uint8_t deviceId_, GPIOType type_):GPIO(deviceId_, type_){};
    virtual ~Switch() = default;

    bool registerHandler(gpioISRFuncEx_t fun, const int &edge, const int &timeout = 0, void *intData = nullptr);

private:

    gpioISRFuncEx_t interruptHandler = nullptr;
    void *interruptData = nullptr;
};


#endif //SAFEHOUSE_SWITCH_H
