#include <iostream>
#include <logger/Logger.h>

#include <packet/ListenStreamTCP.h>
#include <packet/SendStreamTCP.h>

#include <main_rpi/communication_manager_rpi/CommunicationManagerRpi.h>
#include <peripherals/SensorTagManager.h>

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

    //Test bluetooth peripheral:
    SensorTagManager tagManager;
    std::cout << "Starting bluetooth test." << std::endl;
    if(tagManager.initBluetooth())
    {
        tagManager.scanDevicesTest();
        std::cout << "Bluetooth test complete." << std::endl;
    }
    else
    {
        std::cout << "Bluetooth test failed." << std::endl;
    }

    CommunicationManagerRpi manager(9000,4);
    manager.initialize();

    while(1)
    {

    }

    return 0;
}
