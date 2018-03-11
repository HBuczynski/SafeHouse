#include "CommunicationManagerClient.h"

#include <protocol/BlindsDOWNOnTimeCommand.h>
#include <protocol/BlindsDOWNCommand.h>
#include <protocol/BlindsUPOnTimeCommand.h>
#include <protocol/EndConnectionCommand.h>

#include <iostream>

#include <thread>
#include <chrono>

using namespace std;
using namespace communication;

CommunicationManagerClient::CommunicationManagerClient(CommunicationParameters parameters)
    :   parameters_(parameters)
{
    client_ = make_unique<ClientTCP>(parameters_.destinationPortTCP, parameters_.destinationAddressTCP);
}

CommunicationManagerClient::~CommunicationManagerClient()
{
}

void CommunicationManagerClient::initializeClientConnection()
{
    client_->connectToServer();
    client_->startCommandListeningAndSending();
}

void CommunicationManagerClient::sendCommands()
{
    auto command2 = make_unique<EndConnectionCommand>();

    std::this_thread::sleep_for(1s);
    client_->sendCommand(move(command2));
    std::this_thread::sleep_for(1s);

}



