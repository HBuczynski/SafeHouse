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


    CommunicationParameters paramters;
    paramters.destinationAddressTCP = "89.65.72.7";
    paramters.destinationPortTCP = 9000;


    CommunicationManagerClient manager(paramters);
    manager.initializeClientConnection();
    manager.sendCommands();

    while(1)
    {


    }

    return 0;
}
