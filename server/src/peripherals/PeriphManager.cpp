#include "PeriphManager.h"
#include "MotionSensor.h"
#include "Camera.h"
#include "protocol/BlindsStatusResponse.h"
#include <protocol/DataResponse.h>
#include <config_reader/JSONParser.h>

using namespace std;
using namespace communication;
using namespace peripherials;
using namespace config;

PeriphManager *PeriphManager::instance_= nullptr;
std::mutex PeriphManager::periphManagerMutex_;

vector <unique_ptr<GPIO>> PeriphManager::connectedDevices;
vector <unique_ptr<Blinds> > PeriphManager::connectedBlinds;


PeriphManager::PeriphManager()
{
}

PeriphManager::~PeriphManager()
{
    gpioTerminate();
}

PeriphManager &PeriphManager::getInstance()
{
    if (!instance_)
    {
        lock_guard<mutex> lock(periphManagerMutex_);
        if (!instance_)
        {
            instance_ = new PeriphManager();
		
            gpioCfgSocketPort(9500);
	    gpioCfgInterfaces(PI_DISABLE_SOCK_IF);

            gpioInitialise();
            initialize();
        }
    }

    return *instance_;
}

void PeriphManager::initialize()
{
    readConfig("../../config.json");
}

void PeriphManager::readConfig(const std::string &configFile)
{
    JSONParser parser(configFile);

    // Create blinds based on data from file.
    for(uint8_t i=1; i<=1; ++i)
    {
        stringstream ss;

        ss << "Blinds_" << to_string(i);

        vector<string> blindElements;
        blindElements.push_back("Peripherals");
        blindElements.push_back(ss.str());

        uint8_t id;
        blindElements.push_back("id");
        parser.getUINT8t(blindElements, id);
        blindElements.pop_back();

        uint16_t motorPin;
        blindElements.push_back("motorPin");
        parser.getUINT16t(blindElements, motorPin);
        blindElements.pop_back();

        uint16_t motorPinPWMLeft;
        blindElements.push_back("motorPinPWMLeft");
        parser.getUINT16t(blindElements, motorPinPWMLeft);
        blindElements.pop_back();

        uint16_t motorPinPWMRight;
        blindElements.push_back("motorPinPWMRight");
        parser.getUINT16t(blindElements, motorPinPWMRight);
        blindElements.pop_back();

        uint16_t motorPinPWMEnable;
        blindElements.push_back("motorPinPWMEnable");
        parser.getUINT16t(blindElements, motorPinPWMEnable);
        blindElements.pop_back();

        uint16_t upperSwitchPin;
        blindElements.push_back("upperSwitchPin");
        parser.getUINT16t(blindElements, upperSwitchPin);
        blindElements.pop_back();

        uint16_t lowerSwitchPin;
        blindElements.push_back("lowerSwitchPin");
        parser.getUINT16t(blindElements, lowerSwitchPin);
        blindElements.pop_back();

        auto blinds = make_unique<Blinds>(id);
        blinds->init(motorPin, motorPinPWMLeft, motorPinPWMRight, motorPinPWMEnable, upperSwitchPin, lowerSwitchPin);

        connectedBlinds.push_back(move(blinds));
    }


    // Temperature sensor.
    vector<string> temperatureElements;
    temperatureElements.push_back("Peripherals");
    temperatureElements.push_back("Temperature_sensor");

    uint8_t temperatureID;
    temperatureElements.push_back("id");
    parser.getUINT8t(temperatureElements, temperatureID);
    temperatureElements.pop_back();

    uint16_t temperaturePin;
    temperatureElements.push_back("pinNumber");
    parser.getUINT16t(temperatureElements, temperaturePin);
    temperatureElements.pop_back();

    auto temperatureSensor = make_unique<TemperatureSensor>(temperatureID);
    //TO DO - the rest elements
    temperatureSensor->setMode(temperaturePin, 0, 0);
    temperatureSensor->init();
    connectedDevices.push_back(move(temperatureSensor));


    // Camera
    vector<string> cameraElements;
    cameraElements.push_back("Peripherals");
    cameraElements.push_back("Camera");

    uint8_t cameraID;
    cameraElements.push_back("id");
    parser.getUINT8t(cameraElements, cameraID);

    auto camera = make_unique<Camera>(cameraID);
    connectedDevices.push_back(move(camera));


    // Motion sensor
    vector<string> motionElements;
    motionElements.push_back("Peripherals");
    motionElements.push_back("Motion_sensor");

    uint8_t motionID;
    motionElements.push_back("id");
    parser.getUINT8t(motionElements, motionID);
    motionElements.pop_back();

    uint16_t motionPin;
    motionElements.push_back("pinNumber");
    parser.getUINT16t(motionElements, motionPin);
    motionElements.pop_back();

    auto motionSensor = make_unique<MotionSensor>(motionID);
    motionSensor->setMode(motionPin, PI_INPUT, PI_PUD_OFF);
    motionSensor->init();
    motionSensor->setSensor(false);
    connectedDevices.push_back(move(motionSensor));
}

void PeriphManager::initBroadcastFucntion(function<void(shared_ptr<Response>)> broadcastFunction)
{
    broadcastFunction_ = broadcastFunction;
}

void PeriphManager::runBlindsDOWNOnTime(uint32_t epochTime)
{
    lock_guard<mutex> lock(commandMutex_);
}

void PeriphManager::runBlindsUPOnTime(int32_t epochTime)
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runBlindsUP()
{
    lock_guard<mutex> lock(commandMutex_);
    for(unsigned int i = 0; i < connectedBlinds.size(); ++i)
    {
        connectedBlinds[i]->actualState->blindsUp(*connectedBlinds[i].get());
    }
}

void PeriphManager::runBlindsDOWN()
{
    lock_guard<mutex> lock(commandMutex_);
    for(unsigned int i = 0; i < connectedBlinds.size(); ++i)
    {
        connectedBlinds[i]->actualState->blindsDown(*connectedBlinds[i].get());
    }

}

void PeriphManager::runBlindsStatus()
{
    lock_guard<mutex> lock(commandMutex_);
    for(unsigned int i = 0; i < connectedBlinds.size(); ++i)
    {   //TODO: Make BlindStatus and mode enum in common directory, differentiate blinds by IDs:
        const auto blindStatusResponse = std::make_shared<BlindsStatusResponse>(UP, MANUAL);
        broadcast(blindStatusResponse);
    }
}

void PeriphManager::runAutomaticBlinds()
{
    lock_guard<mutex> lock(commandMutex_);


}

void PeriphManager::runTemperatureDemand()
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runUserOutOfHome()
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runSnapshot()
{
    lock_guard<mutex> lock(commandMutex_);
    system("../../camera_scripts/take_snapshot.sh");
}

void PeriphManager::broadcast(shared_ptr<Response> response)
{
    broadcastFunction_(response);
}
