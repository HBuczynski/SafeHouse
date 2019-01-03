#ifndef SAFEHOUSE_SENSORTAGMANAGER_H
#define SAFEHOUSE_SENSORTAGMANAGER_H


#include <../../3rd_party/tinyb/api/tinyb.hpp>

#include <vector>
#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>
#include <memory>

#define HUMIDITY_UUID "f000aa20-0451-4000-b000-000000000000"
#define HUMIDITY_CONFIG "f000aa22-0451-4000-b000-000000000000"
#define HUMIDITY_MEAS_UUID "f000aa21-0451-4000-b000-000000000000"
#define TEMPERATURE_UUID "f000aa00-0451-4000-b000-000000000000"
#define TEMPERATURE_MEAS_UUID "f000aa01-0451-4000-b000-000000000000"
#define TEMPERATURE_CONFIG "f000aa02-0451-4000-b000-000000000000"
#define OPTICAL_UUID "f000aa40-0451-4000-b000-000000000000"
#define OPTICAL_MEAS_UUID "f000aa41-0451-4000-b000-000000000000"
#define OPTICAL_CONFIG "f000aa42-0451-4000-b000-000000000000"

using namespace tinyb;

static float celsius_temp(uint16_t raw_temp)
{
    const float SCALE_LSB = 0.03125;
    return ((float)(raw_temp >> 2)) * SCALE_LSB;
}


class SensorTagManager {

public:
    SensorTagManager() = default;

    ~SensorTagManager() = default;

    bool initBluetooth();
    void scanDevicesTest(void);
    bool scanSensorTags();
    void connectSensorTags(void);
    std::vector<uint16_t> getMeasurements(void);
    void disconnectSensorTags(void);

private:

    BluetoothManager *bleManager = nullptr;
    std::vector<std::unique_ptr<BluetoothDevice>> sensorTags;
    std::vector<std::unique_ptr<BluetoothGattCharacteristic>> measurementsCharacteristics;
    std::vector<uint16_t> measurementValues;
};

#endif //SAFEHOUSE_SENSORTAGMANAGER_H
