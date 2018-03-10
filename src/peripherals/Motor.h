//
// Created by marcin on 10.03.18.
//

#ifndef SAFEHOUSE_MOTOR_H
#define SAFEHOUSE_MOTOR_H

#include <GPIO.h>

#define DEFAULT_PWM_FREQUENCY 500 //in hertz

class Motor : protected GPIO
{
public:
    Motor() = default;
    virtual ~Motor() = default;
    virtual bool init() const;
    bool setPWM(unsigned int &pwmValue_);
    int getPWM() const;
    bool setRange(const int &pwmUpperRange_) const;
    int getRange() const;
    bool setPWMFrequency(const int &frequency);

private:
    int pwmFrequency = DEFAULT_PWM_FREQUENCY;
};


#endif //SAFEHOUSE_MOTOR_H
