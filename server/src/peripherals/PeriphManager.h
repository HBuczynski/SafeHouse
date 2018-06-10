
#ifndef SAFEHOUSE_PERIPHMANAGER_H
#define SAFEHOUSE_PERIPHMANAGER_H

#include <mutex>

#include "GPIO.h"
#include "Motor.h"
#include "Switch.h"
#include "Blinds.h"
#include "TemperatureSensor.h"
#include <config_reader/JSONParser.h>
#include <protocol/Response.h>

#define CONFIGURATION_FILE "../../config.json"

namespace peripherials
{
    class PeriphManager
    {
    public:
        static PeriphManager &getInstance();

        void initBroadcastFucntion(std::function<void(std::shared_ptr<communication::Response>)> broadcastFunction);

        void runBlindsDOWNOnTime(uint32_t epochTime);
        void runBlindsUPOnTime(int32_t epochTime);
        void runBlindsUP();
        void runBlindsDOWN();
        void runBlindsStatus();
        void runAutomaticBlinds();
        void runTemperatureDemand();
        void runUserOutOfHome();
		void runUserInHome();
        void runSnapshot();

    private:
        PeriphManager();
        ~PeriphManager();

        static void initialize();
        static void readConfig(const std::string &configFile);

        void broadcast(std::shared_ptr<communication::Response> response);

        static std::vector <std::unique_ptr<GPIO>> connectedDevices;
        static std::vector <std::unique_ptr<Blinds> > connectedBlinds;
        static std::unique_ptr<MotionSensor> connectedMotionSensor;
        std::function<void(std::shared_ptr<communication::Response>)> broadcastFunction_;
        std::mutex commandMutex_;

        static PeriphManager *instance_;
        static std::mutex periphManagerMutex_;


    };
}

#endif //SAFEHOUSE_PERIPHMANAGER_H
