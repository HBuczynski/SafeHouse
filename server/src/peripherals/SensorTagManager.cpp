
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

    for(int i = 0; i < sensorTags.size(); ++i)
    {
        std::cout << i << " " << sensorTags[i]->get_object_path() << std::endl;
    }
    /* Stop the discovery (the device was found or number of tries ran out */
    ret = bleManager->stop_discovery();
    std::cout << "Stopped = " << (ret ? "true" : "false") << std::endl;
    std::cout << "Found " << sensorTags.size() << " sensor tags." << std::endl;
    return true;
}

void SensorTagManager::connectDevicesAndGetTemp()
{
    if(bleManager == nullptr)
    {
        std::cout << "BluetoothManager not initialized!" << std::endl;
        return;
    }
    if(sensorTags.size() == 0)
    {
        std::cout << "No devices detected!" << std::endl;
        return;
    }

    /* Connect to the device and get the list of services exposed by it */
    for(int i = 0; i < sensorTags.size(); ++i)
    {
        std::unique_ptr<BluetoothGattService> temperature_service;
        sensorTags[i]->connect();
        std::string service_uuid("f000aa00-0451-4000-b000-000000000000");
        std::cout << "Waiting for service " << service_uuid << " to be discovered" << std::endl;
        temperature_service = sensorTags[i]->find(&service_uuid);

        auto value_uuid = std::string("f000aa01-0451-4000-b000-000000000000");
        auto temp_value = temperature_service->find(&value_uuid);

        auto config_uuid = std::string("f000aa02-0451-4000-b000-000000000000");
        auto temp_config = temperature_service->find(&config_uuid);

        auto period_uuid = std::string("f000aa03-0451-4000-b000-000000000000");
        auto temp_period = temperature_service->find(&period_uuid);

        /* Activate the temperature measurements */
        try {
            std::vector<unsigned char> config_on {0x01};
            temp_config->write_value(config_on);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        /* Read temperature data and display it */
        try {
            std::vector<unsigned char> response = temp_value->read_value();
            unsigned char *data;
            unsigned int size = response.size();
            if (size > 0) {
                data = response.data();

                std::cout << "Raw data=[";
                for (unsigned i = 0; i < response.size(); i++)
                    std::cout << std::hex << static_cast<int>(data[i]) << ", ";
                std::cout << "] ";

                uint16_t ambient_temp, object_temp;
                object_temp = data[0] | (data[1] << 8);
                ambient_temp = data[2] | (data[3] << 8);
                std::cout << "Ambient temp: " << celsius_temp(ambient_temp) << "C ";
                std::cout << "Object temp: " << celsius_temp(object_temp) << "C ";
                std::cout << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));

        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            break;
        }

        /* Disconnect from the device */
        try {
            sensorTags[i]->disconnect();
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}