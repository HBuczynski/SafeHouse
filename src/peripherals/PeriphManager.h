
#ifndef SAFEHOUSE_PERIPHMANAGER_H
#define SAFEHOUSE_PERIPHMANAGER_H

#include <GPIO.h>
#include <Motor.h>
#include <Switch.h>
#include <TemperatureSensor.h>
#include <config_reader/JSONParser.h>

#define CONFIGURATION_FILE "../../config.json"

using namespace std;


class PeriphManager
{
public:

    PeriphManager();
    ~PeriphManager();

    void initialize();

    void readConfig(string configFile);

private:

    vector<unique_ptr<GPIO>> connectedDevices;

};


#endif //SAFEHOUSE_PERIPHMANAGER_H
