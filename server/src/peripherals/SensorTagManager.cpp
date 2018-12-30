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

    for (auto it = sensorTags.begin(); it != sensorTags.end(); ++it) {

        std::cout << "Class = " << (*it)->get_class_name() << " ";
        std::cout << "Path = " << (*it)->get_object_path() << " ";
        std::cout << "Name = " << (*it)->get_name() << " ";
        std::cout << "Connected = " << (*it)->get_connected() << " ";
        std::cout << std::endl;
        /* Remove devices that are not sensor tags */
        if((*it)->get_name().find("SensorTag")!=std::string::npos)
        {
            std::cout << "Found sensor tag!" << std::endl;
        }
    }
    /* Stop the discovery (the device was found or number of tries ran out */
    ret = bleManager->stop_discovery();
    std::cout << "Stopped = " << (ret ? "true" : "false") << std::endl;

}