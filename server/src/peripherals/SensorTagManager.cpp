
#include <algorithm>
#include "SensorTagManager.h"


bool SensorTagManager::initBluetooth()
{
    try {
        bleManager = BluetoothManager::get_bluetooth_manager();
    } catch(const std::runtime_error& e)
    {
        std::cerr << "Error while initializing libtinyb: " << e.what() << std::endl;
        return false;
    }
    std::cout << "Bluetooth initialization successful." << std::endl;
    return true;
}

void SensorTagManager::scanDevicesTest()
{
    if(bleManager == nullptr)
    {
        std::cout << "BluetoothManager not initialized!" << std::endl;
        return;
    }
    bool ret = bleManager->start_discovery();
    std::cout << "Started = " << (ret ? "true" : "false") << std::endl;
    for (int i = 0; i < 15; ++i) {
        std::cout << "Discovered devices: " << std::endl;
/* Get the list of devices */
        auto list = bleManager->get_devices();

        for (auto it = list.begin(); it != list.end(); ++it) {

            std::cout << "Class = " << (*it)->get_class_name() << " ";
            std::cout << "Path = " << (*it)->get_object_path() << " ";
            std::cout << "Name = " << (*it)->get_name() << " ";
            std::cout << "Connected = " << (*it)->get_connected() << " ";
            std::cout << std::endl;

        }
    }

    /* Stop the discovery (the device was found or number of tries ran out */
    ret = bleManager->stop_discovery();
    std::cout << "Stopped = " << (ret ? "true" : "false") << std::endl;
}

bool SensorTagManager::scanSensorTags()
{
    if(bleManager == nullptr)
    {
        std::cout << "BluetoothManager not initialized!" << std::endl;
        return false;
    }
    bool ret = bleManager->start_discovery();
    std::cout << "Started = " << (ret ? "true" : "false") << std::endl;
    sensorTags = bleManager->get_devices();

    sensorTags.erase(std::remove_if(sensorTags.begin(), sensorTags.end(), [](auto& item) {
                return item->get_name().find("SensorTag") == std::string::npos;
            }), sensorTags.end());

    for(unsigned int i = 0; i < sensorTags.size(); ++i)
    {
        std::cout << i << " " << sensorTags[i]->get_object_path() << std::endl;
    }
    /* Stop the discovery (the device was found or number of tries ran out */
    ret = bleManager->stop_discovery();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Stopped = " << (ret ? "true" : "false") << std::endl;
    std::cout << "Found " << sensorTags.size() << " sensor tags." << std::endl;
    measurementsCharacteristics.resize(3*sensorTags.size());
    measurementValues.resize(3*sensorTags.size());
    return true;
}

bool SensorTagManager::scanSensorTagsManually()
{
    bool ret = false;
    if(bleManager == nullptr)
    {
        std::cout << "BluetoothManager not initialized!" << std::endl;
        return false;
    }
    std::cout << "Started = " << (ret ? "true" : "false") << std::endl;
    sensorTags.clear();

    std::string device_mac(SENSOR_TAG_1);
    auto sensorTag = bleManager->find<BluetoothDevice>(nullptr, &device_mac, nullptr, std::chrono::milliseconds(100));
    if(sensorTag != nullptr)
    {
        std::cout << "Device "<< SENSOR_TAG_1 <<" found" << std::endl;
        sensorTags.push_back(std::move(sensorTag));
    }

    device_mac = SENSOR_TAG_2;
    sensorTag = bleManager->find<BluetoothDevice>(nullptr, &device_mac, nullptr, std::chrono::milliseconds(100));
    if(sensorTag != nullptr)
    {
        std::cout << "Device "<< SENSOR_TAG_2 <<" found" << std::endl;
        sensorTags.push_back(std::move(sensorTag));
    }

    device_mac = SENSOR_TAG_3;
    sensorTag = bleManager->find<BluetoothDevice>(nullptr, &device_mac, nullptr, std::chrono::milliseconds(100));
    if(sensorTag != nullptr)
    {
        std::cout << "Device "<< SENSOR_TAG_3 <<" found" << std::endl;
        sensorTags.push_back(std::move(sensorTag));
    }
    std::cout << "Found " << sensorTags.size() << " sensor tags." << std::endl;
    measurementsCharacteristics.resize(3*sensorTags.size());
    measurementValues.resize(3*sensorTags.size());
    return true;
}

std::vector<uint16_t> SensorTagManager::getMeasurements()
{
    /* Read measurements data and display it */
    for(unsigned int i = 0; i < measurementValues.size(); ++i)
    {
        if(!sensorTags[i%3]->get_connected())
            continue;
        try {
            std::cout << "Read measurement:" << i << std::endl;
            std::vector<unsigned char> response = measurementsCharacteristics[i]->read_value();
            unsigned char *data;
            unsigned int size = response.size();
            if (size > 0) {
                data = response.data();

                std::cout << "Raw data=[";
                for (unsigned i = 0; i < response.size(); i++)
                    std::cout << std::hex << static_cast<int>(data[i]) << ", ";
                std::cout << "] ";
                if(response.size() == 6)
                {
                    measurementValues[i] = (uint16_t)((data[3] | (data[4] << 8) | (data[5] << 16)/100));

                }
                else
                {
                    measurementValues[i] = data[2] | (data[3] << 8);
                }
                std::cout << "Measurement: " << measurementValues[i];
                std::cout << std::endl;
            }
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            continue;
        }
    }
    return measurementValues;
}

void SensorTagManager::connectSensorTags() {
    if (bleManager == nullptr) {
        std::cout << "BluetoothManager not initialized!" << std::endl;
        return;
    }
    if (sensorTags.size() == 0) {
        std::cout << "No devices detected!" << std::endl;
        return;
    }

    /* Connect to the device and get the list of services exposed by it */
    for (unsigned int i = 0; i < sensorTags.size(); ++i) {
        try {
            sensorTags[i]->connect();
        }
        catch (std::exception &e) {
            std::cout << "Exception thrown: " << e.what() << std::endl;
            break;
        }
    }
}

void SensorTagManager::checkServicesSensorTags()
{
    for (unsigned int i = 0; i < sensorTags.size(); ++i)
    {
        if(!sensorTags[i]->get_connected())
            continue;
        std::unique_ptr <BluetoothGattService> temperature_service;
        std::string service_uuid_temp(TEMPERATURE_UUID);
        std::cout << "Waiting for service " << service_uuid_temp << " to be discovered" << std::endl;
        temperature_service = sensorTags[i]->find(&service_uuid_temp, std::chrono::milliseconds(100));

        auto value_uuid = std::string(TEMPERATURE_MEAS_UUID);
        measurementsCharacteristics[3*i] = temperature_service->find(&value_uuid, std::chrono::milliseconds(100));

        auto config_uuid = std::string(TEMPERATURE_CONFIG);
        auto config = temperature_service->find(&config_uuid, std::chrono::milliseconds(100));

        /* Activate the temperature measurements */
        try {
            std::cout << "Invoking temperature measurement" << std::endl;
            std::vector<unsigned char> config_on {0x01};
            config->write_value(config_on);

        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::unique_ptr<BluetoothGattService> humid_service;
        std::string service_uuid_humid(HUMIDITY_UUID);
        std::cout << "Waiting for service " << service_uuid_humid << " to be discovered" << std::endl;
        humid_service = sensorTags[i]->find(&service_uuid_humid);

        value_uuid = std::string(HUMIDITY_MEAS_UUID);
        measurementsCharacteristics[3*i+1] = humid_service->find(&value_uuid, std::chrono::milliseconds(100));

        config_uuid = std::string(HUMIDITY_CONFIG);
        config = humid_service->find(&config_uuid, std::chrono::milliseconds(100));

        /* Activate the temperature measurements */
        try {
            std::cout << "Invoking humidity measurement" << std::endl;
            std::vector<unsigned char> config_on {0x01};
            config->write_value(config_on);

        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::unique_ptr<BluetoothGattService> optic_service;
        std::string service_uuid_optic(OPTICAL_UUID);
        std::cout << "Waiting for service " << service_uuid_optic << " to be discovered" << std::endl;
        optic_service = sensorTags[i]->find(&service_uuid_optic, std::chrono::milliseconds(100));

        value_uuid = std::string(OPTICAL_MEAS_UUID);
        measurementsCharacteristics[3*i+2] = optic_service->find(&value_uuid, std::chrono::milliseconds(100));

        config_uuid = std::string(OPTICAL_CONFIG);
        config = optic_service->find(&config_uuid, std::chrono::milliseconds(100));

        /* Activate the temperature measurements */
        try {
            std::cout << "Invoking pressure measurement" << std::endl;
            std::vector<unsigned char> config_on {0x01};
            config->write_value(config_on);

        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    }
}

void SensorTagManager::disconnectSensorTags()
{
    for(unsigned int i = 0; i < sensorTags.size(); ++i)
    {
        /* Disconnect from the device */
        try {
            std::cout << "Disconnect sensor tag" << std::endl;
            sensorTags[i]->disconnect();
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}