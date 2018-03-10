#include <iostream>
#include <logger/Logger.h>


#include <packet/ListenStreamTCP.h>
#include <packet/SendStreamTCP.h>
#include <main_client/communication_manager_client/CommunicationManagerClient.h>

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


    //CommunicationParameters paramters;
    /*paramters.sourceAddressUDP = "192.168.0.185";
    paramters.sourcePortUDP = 8000;
    paramters.destinationAddressTCP = "192.168.0.164";
    paramters.destinationPortTCP = 9000;*/

    /*paramters.sourceAddressUDP = "127.0.0.1";
    paramters.sourcePortUDP = 8000;
    paramters.destinationAddressTCP = "127.0.0.1";
    paramters.destinationPortTCP = 9000;

    CommunicationManagerClient manager(paramters);
    manager.initializeServer();
    manager.initializeClientConnection();
    manager.sendCommands();*/

    while(1)
    {


    }

    return 0;
}
