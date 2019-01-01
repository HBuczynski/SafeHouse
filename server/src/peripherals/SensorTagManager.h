#ifndef SAFEHOUSE_SENSORTAGMANAGER_H
#define SAFEHOUSE_SENSORTAGMANAGER_H


#include <../../3rd_party/tinyb/api/tinyb.hpp>

#include <vector>
#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>
#include <memory>

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
