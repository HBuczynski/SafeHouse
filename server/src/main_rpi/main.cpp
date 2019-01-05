#include <iostream>
#include <logger/Logger.h>

#include <packet/ListenStreamTCP.h>
#include <packet/SendStreamTCP.h>

#include <main_rpi/communication_manager_rpi/CommunicationManagerRpi.h>

#include <SensorTagManager.h>

using namespace std;
using namespace utility;
using namespace communication;

int main(int argc , char *argv[])
{
    Logger &logger = Logger::getInstance();

    InitLogStructure struc;
    struc.debugLog = true;
    struc.errroLog = true;
    struc.informationLog = true;
    struc.warningLog = true;

    struc.writeLogsInSeparetFiles = true;
    struc.writeOnConsole = true;

    logger.initLogger(struc);

    CommunicationManagerRpi manager(9000,4);
    manager.initialize();

    while(1)
    {
    }

//    SensorTagManager tagManager;
//    if(tagManager.initBluetooth()){
//        tagManager.scanSensorTagsManually();
//        tagManager.connectSensorTags();
//    }
//    else{
//        return 0;
//    }
//
//    vector<uint16_t> data(9);
//    tagManager.checkServicesSensorTags();
//    vector<uint16_t> temp = tagManager.getMeasurements();
//    for(unsigned int i = 0; i < temp.size(); ++i)
//    {
//        data[i] = temp[i];
//        std::cout << "Data " << i << ": " << data[i] << std::endl;
//    }
//
//    tagManager.disconnectSensorTags();

    return 0;
}
