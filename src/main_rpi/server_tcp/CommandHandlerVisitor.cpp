#include "CommandHandlerVisitor.h"

#include <protocol/DataResponse.h>


#include <main_rpi/server_tcp/ClientThreadTCP.h>

#include <iostream>

#include <GPIO.h>

using namespace std;
using namespace utility;
using namespace communication;

CommandHandlerVisitor::CommandHandlerVisitor()
    : logger_(Logger::getInstance())
{}

CommandHandlerVisitor::~CommandHandlerVisitor()
{}



void CommandHandlerVisitor::visit(BlindsDOWNOnTimeCommand &command)
{
    /*auto newClient = make_shared<ClientUDP>(command.getPort(), command.getAddress());

    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandler :: Received BlindsDOWNOnTimeCommand from ClientID -") +
                         to_string(currentClient_->getID())
                         + string("-. Command data: port-") + to_string(command.getPort()) + string("; address-") +
                         command.getAddress();
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    clientUDPManager_->insertNewClient(make_pair((newClient), currentClient_->getID()));*/

    cout << "BlindsDOWNOnTimeCommand" << endl;

    gpioInitialise();

    GPIO diode;
    diode.setMode(16, PI_OUTPUT, PI_PUD_OFF);
    diode.init();
    diode.pinWrite(1);
    
    response_ = make_unique<DataResponse>("OK");
}

void CommandHandlerVisitor::visit(BlindsUPOnTimeCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandler :: Received BlindsUPOnTimeCommand from ClientID -") +
                         to_string(currentClient_->getID())
                         + string("-.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    cout << "BlindsUPOnTimeCommand" << endl;;

    response_ = make_unique<DataResponse>("OK");
}

void CommandHandlerVisitor::visit(BlindsUPCommand &command)
{
    cout << "BlindsUPCommand" << endl;;

    response_ = make_unique<DataResponse>("OK");
}

void CommandHandlerVisitor::visit(BlindsDOWNCommand &command)
{
    cout << "BlindsDOWNCommand" << endl;;

    response_ = make_unique<DataResponse>("OK");
}

void CommandHandlerVisitor::visit(BlindsStatusCommand &command)
{
    cout << "BlindsStatusCommand" << endl;;

    response_ = make_unique<DataResponse>("OK");
}

void CommandHandlerVisitor::visit(AutomaticBlindsCommand &command)
{
    cout << "AutomaticBlindsCommand" << endl;;

    response_ = make_unique<DataResponse>("OK");
}

unique_ptr<Response> CommandHandlerVisitor::getResponse()
{
    return move(response_);
}

void CommandHandlerVisitor::initializeCurrentClient(ClientThreadTCP *client)
{
    currentClient_ = client;
}

