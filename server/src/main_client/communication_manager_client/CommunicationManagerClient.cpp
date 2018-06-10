#include "CommunicationManagerClient.h"

#include <protocol/StartStreamCommand.h>
#include <protocol/BlindsDOWNCommand.h>
#include <protocol/BlindsUPCommand.h>
#include <protocol/StopStreamCommand.h>

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
    auto command  = make_unique<BlindsDOWNCommand>();
    std::this_thread::sleep_for(1s);
    client_->sendCommand(move(command));

    auto command  = make_unique<BlindsUPCommand>();
    std::this_thread::sleep_for(1s);
    client_->sendCommand(move(command));

    auto command  = make_unique<BlindsUPCommand>();
    std::this_thread::sleep_for(1s);
    client_->sendCommand(move(command));
//    auto command2 = make_unique<StartStreamCommand>();
//    std::this_thread::sleep_for(1s);
//    client_->sendCommand(move(command2));
//
//    std::this_thread::sleep_for(10s);
//    auto command3 = make_unique<StopStreamCommand>();
//    client_->sendCommand(move(command3));
//
//    std::this_thread::sleep_for(20s);
//    auto command4 = make_unique<StartStreamCommand>();
//    client_->sendCommand(move(command4));
}



