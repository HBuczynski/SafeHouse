#include "CommandHandlerVisitor.h"

#include <protocol/DataResponse.h>
#include <main_rpi/server_tcp/ClientThreadTCP.h>

#include <iostream>

//#include <GPIO.h>

using namespace std;
using namespace utility;
using namespace peripherials;
using namespace communication;

CommandHandlerVisitor::CommandHandlerVisitor()
    : logger_(Logger::getInstance()),
      periphManager_(PeriphManager::getInstance())
{}

CommandHandlerVisitor::~CommandHandlerVisitor()
{}

void CommandHandlerVisitor::visit(BlindsDOWNOnTimeCommand &command)
{
    periphManager_.runBlindsDOWNOnTime(command.getEpochDateAndTime());
}

void CommandHandlerVisitor::visit(BlindsUPOnTimeCommand &command)
{
    periphManager_.runBlindsUPOnTime(command.getEpochDateAndTime());
}

void CommandHandlerVisitor::visit(BlindsUPCommand &command)
{
    periphManager_.runBlindsUP();
}

void CommandHandlerVisitor::visit(BlindsDOWNCommand &command)
{
    periphManager_.runBlindsDOWN();
}

void CommandHandlerVisitor::visit(BlindsStatusCommand &command)
{
    periphManager_.runBlindsStatus();
}

void CommandHandlerVisitor::visit(AutomaticBlindsCommand &command)
{
    periphManager_.runAutomaticBlinds();
}

void CommandHandlerVisitor::visit(TemperatureDemandCommand &command)
{
    periphManager_.runTemperatureDemand();
}

void CommandHandlerVisitor::visit(UserOutOfHomeCommand &command)
{
    periphManager_.runUserOutOfHome();
}

void CommandHandlerVisitor::visit(SnapshotCommand &command)
{
    periphManager_.runSnapshot();
}

void CommandHandlerVisitor::visit(EndConnectionCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ClientThreadTCP :: ClientdID -") + to_string(currentClient_->getID()) + string("- end connection.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    currentClient_->stopSendAndListen();
}

void CommandHandlerVisitor::initializeCurrentClient(ClientThreadTCP *client)
{
    currentClient_ = client;
}
