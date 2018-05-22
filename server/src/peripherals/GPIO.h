#ifndef SAFEHOUSE_GPIO_H
#define SAFEHOUSE_GPIO_H

#include <../../3rd_party/PIGPIO/pigpio.h>
#include <logger/Logger.h>

#define INVALID_DEVICE_ID -1

enum GPIOType : uint8_t
{
    MOTOR = 0,
    UPPER_SWITCH,
    DOWN_SWITCH,
    TEMPERATURE_SENSOR,
    CAMERA,
    MOTION_SENSOR
};

class GPIO {
public:
    GPIO():deviceId(INVALID_DEVICE_ID) {};
    GPIO(uint8_t deviceId_, GPIOType type_);
    virtual ~GPIO() = default;

    virtual bool init() const;
    virtual void setMode(uint8_t pinNumber_, uint8_t pinMode_, uint8_t pushPullMode_);

    virtual void pinWrite(int state);
    virtual int pinRead() const;

protected:
    //Peripheral id:
    uint16_t deviceId = 0;
    GPIOType deviceType;
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
