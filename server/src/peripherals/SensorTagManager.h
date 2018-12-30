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
    void connectDevicesAndGetTemp(void);

    uint16_t ambientTemp = 0;


private:

    BluetoothManager *bleManager = nullptr;
    std::vector<std::unique_ptr<BluetoothDevice>> sensorTags;
};


//BluetoothManager *manager = nullptr;
//try {
//manager = BluetoothManager::get_bluetooth_manager();
//} catch(const std::runtime_error& e) {
//std::cerr << "Error while initializing libtinyb: " << e.what() << std::endl;
//exit(1);
//}
//
///* Start the discovery of devices */
//bool ret = manager->start_discovery();
//std::cout << "Started = " << (ret ? "true" : "false") << std::endl;
//
//BluetoothDevice *sensor_tag = NULL;
//BluetoothGattService *temperature_service = NULL;
//
//for (int i = 0; i < 15; ++i) {
//std::cout << "Discovered devices: " << std::endl;
///* Get the list of devices */
//auto list = manager->get_devices();

//for (auto it = list.begin(); it != list.end(); ++it) {
//
//std::cout << "Class = " << (*it)->get_class_name() << " ";
//std::cout << "Path = " << (*it)->get_object_path() << " ";
//std::cout << "Name = " << (*it)->get_name() << " ";
//std::cout << "Connected = " << (*it)->get_connected() << " ";
//std::cout << std::endl;
//
///* Search for the device with the address given as a parameter to the program */
//if ((*it)->get_address() == argv[1])
//sensor_tag = (*it).release();
//}
//
///* Free the list of devices and stop if the device was found */
//if (sensor_tag != nullptr)
//break;
///* If not, wait and try again */
//std::this_thread::sleep_for(std::chrono::seconds(4));
//std::cout << std::endl;
//}
//
///* Stop the discovery (the device was found or number of tries ran out */
//ret = manager->stop_discovery();
//std::cout << "Stopped = " << (ret ? "true" : "false") << std::endl;
//
//if (sensor_tag == nullptr) {
//std::cout << "Could not find device " << argv[1] << std::endl;
//return 1;
//}
//
///* Connect to the device and get the list of services exposed by it */
//sensor_tag->connect();
//std::cout << "Discovered services: " << std::endl;
//while (true) {
///* Wait for the device to come online */
//std::this_thread::sleep_for(std::chrono::seconds(4));
//
//auto list = sensor_tag->get_services();
//if (list.empty())
//continue;
//
//for (auto it = list.begin(); it != list.end(); ++it) {
//std::cout << "Class = " << (*it)->get_class_name() << " ";
//std::cout << "Path = " << (*it)->get_object_path() << " ";
//std::cout << "UUID = " << (*it)->get_uuid() << " ";
//std::cout << "Device = " << (*it)->get_device().get_object_path() << " ";
//std::cout << std::endl;
//
///* Search for the temperature service, by UUID */
//if ((*it)->get_uuid() == "f000aa00-0451-4000-b000-000000000000")
//temperature_service = (*it).release();
//}
//break;
//}
//
//if (temperature_service == nullptr) {
//std::cout << "Could not find service f000aa00-0451-4000-b000-000000000000" << std::endl;
//return 1;
//}
//
//BluetoothGattCharacteristic *temp_value = nullptr;
//BluetoothGattCharacteristic *temp_config = nullptr;
//BluetoothGattCharacteristic *temp_period = nullptr;
//
///* If there is a temperature service on the device with the given UUID,
// * get it's characteristics, by UUID again */
//auto list = temperature_service->get_characteristics();
//std::cout << "Discovered characteristics: " << std::endl;
//for (auto it = list.begin(); it != list.end(); ++it) {
//
//std::cout << "Class = " << (*it)->get_class_name() << " ";
//std::cout << "Path = " << (*it)->get_object_path() << " ";
//std::cout << "UUID = " << (*it)->get_uuid() << " ";
//std::cout << "Service = " << (*it)->get_service().get_object_path() << " ";
//std::cout << std::endl;
//
//if ((*it)->get_uuid() == "f000aa01-0451-4000-b000-000000000000")
//temp_value = (*it).release();
//else if ((*it)->get_uuid() =="f000aa02-0451-4000-b000-000000000000")
//temp_config = (*it).release();
//else if ((*it)->get_uuid() == "f000aa03-0451-4000-b000-000000000000")
//temp_period = (*it).release();
//}
//
//if (temp_config == nullptr || temp_value == nullptr || temp_period == nullptr) {
//std::cout << "Could not find characteristics." << std::endl;
//return 1;
//}
//
///* Activate the temperature measurements */
//try {
//std::vector<unsigned char> config_on {0x01};
//temp_config->write_value(config_on);
//while (running) {
///* Read temperature data and display it */
//std::vector<unsigned char> response = temp_value->read_value();
//unsigned char *data;
//unsigned int size = response.size();
//if (size > 0) {
//data = response.data();
//
//std::cout << "Raw data=[";
//for (unsigned i = 0; i < response.size(); i++)
//std::cout << std::hex << static_cast<int>(data[i]) << ", ";
//std::cout << "] ";
//
//uint16_t ambient_temp, object_temp;
//object_temp = data[0] | (data[1] << 8);
//ambient_temp = data[2] | (data[3] << 8);
//
//std::cout << "Ambient temp: " << celsius_temp(ambient_temp) << "C ";
//std::cout << "Object temp: " << celsius_temp(object_temp) << "C ";
//std::cout << std::endl;
//}
//
//std::this_thread::sleep_for(std::chrono::seconds(1));
//}
//} catch (std::exception &e) {
//std::cout << "Error: " << e.what() << std::endl;
//}
//
///* Disconnect from the device */
//try {
//sensor_tag->disconnect();
//} catch (std::exception &e) {
//std::cout << "Error: " << e.what() << std::endl;
//}
//return 0;


#endif //SAFEHOUSE_SENSORTAGMANAGER_H
