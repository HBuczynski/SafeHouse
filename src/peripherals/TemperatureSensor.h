//
// Created by marcin on 11.03.18.
//

#ifndef SAFEHOUSE_TEMPERATURESENSOR_H
#define SAFEHOUSE_TEMPERATURESENSOR_H

#include "GPIO.h"

class TemperatureSensor: protected GPIO
{
public:
    TemperatureSensor() = default;
    TemperatureSensor(uint16_t deviceId_):GPIO(deviceId_, GPIOType::TEMPERATURE_SENSOR){};

    uint16_t readTemperature() const;
};


#endif //SAFEHOUSE_TEMPERATURESENSOR_H
