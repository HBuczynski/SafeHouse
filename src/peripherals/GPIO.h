//
// Created by marcin on 10.03.18.
//

#ifndef SAFEHOUSE_GPIO_H
#define SAFEHOUSE_GPIO_H

#include "PIGPIO/pigpio.h"


class GPIO {
public:
    GPIO() = default;
    virtual ~GPIO() = default;
    virtual bool init() const;
    virtual bool setMode(uint8_t pinNumber_, uint8_t pinMode_, uint8_t pushPullMode_);

protected:
    //BCM Pin number:
    uint8_t pinNumber = 1;
    //Pin mode (INPUT, OUTPUT, ALT0-5):
    //For alternative modes see:
    // https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2835/BCM2835-ARM-Peripherals.pdf , page 102
    uint8_t pinMode = PI_OUTPUT;
    //Push-pull mode (OFF, PULL-UP, PULL-DOWN):
    uint8_t pushPullMode = PI_PUD_OFF;

};


#endif //SAFEHOUSE_GPIO_H
