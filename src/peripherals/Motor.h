
#ifndef SAFEHOUSE_MOTOR_H
#define SAFEHOUSE_MOTOR_H

#include "GPIO.h"

#define DEFAULT_PWM_FREQUENCY 500 //in hertz

class Blinds;

class Motor : public GPIO
{
public:
    Motor(uint8_t deviceId_):GPIO(deviceId_, GPIOType::MOTOR){};
    virtual ~Motor() = default;

    virtual bool init() const;

    bool setPWM(unsigned int pwmValue_, uint8_t pinNumber);
    int getPWM() const;

    bool setRange(const int &pwmUpperRange_) const;
    int getRange() const;

    bool setPWMFrequency(const int frequency, uint8_t pinNumber);

    bool setMotorPins(uint8_t leftPWM, uint8_t rightPWM, uint8_t enable);

private:
    int pwmFrequency = DEFAULT_PWM_FREQUENCY;
    uint8_t PWMLeftPin = 1;
    uint8_t PWMRightPin = 2;
    uint8_t enablePin = 3;
};


#endif //SAFEHOUSE_MOTOR_H
