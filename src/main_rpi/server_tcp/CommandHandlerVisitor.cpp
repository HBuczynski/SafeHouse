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
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsDOWNOnTimeCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsDOWNOnTime(command.getEpochDateAndTime());
}

void CommandHandlerVisitor::visit(BlindsUPOnTimeCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsUPOnTimeCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsUPOnTime(command.getEpochDateAndTime());
}

void CommandHandlerVisitor::visit(BlindsUPCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsUPCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsUP();
}

void CommandHandlerVisitor::visit(BlindsDOWNCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsDOWNCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsDOWN();
}

void CommandHandlerVisitor::visit(BlindsStatusCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsStatusCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsStatus();
}

void CommandHandlerVisitor::visit(AutomaticBlindsCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: AutomaticBlindsCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runAutomaticBlinds();
}

void CommandHandlerVisitor::visit(TemperatureDemandCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: TemperatureDemandCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runTemperatureDemand();
}

void CommandHandlerVisitor::visit(UserOutOfHomeCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: UserOutOfHomeCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runUserOutOfHome();
}

void CommandHandlerVisitor::visit(SnapshotCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: SnapshotCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

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
