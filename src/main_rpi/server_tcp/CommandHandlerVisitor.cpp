#include "CommandHandlerVisitor.h"

#include <protocol/DataResponse.h>
#include <main_rpi/server_tcp/ClientThreadTCP.h>

#include <iostream>

//#include <GPIO.h>

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

    cout << "BlindsDOWNOnTimeCommand" << endl;

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
}

void CommandHandlerVisitor::visit(BlindsUPOnTimeCommand &command)
{
    cout << "BlindsUPOnTimeCommand" << endl;

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
}

void CommandHandlerVisitor::visit(BlindsUPCommand &command)
{
    cout << "BlindsUPCommand" << endl;

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
}

void CommandHandlerVisitor::visit(BlindsDOWNCommand &command)
{
    cout << "BlindsDOWNCommand" << endl;

    /*gpioInitialise();

    GPIO diode;
    diode.setMode(16, PI_OUTPUT, PI_PUD_OFF);
    diode.init();
    diode.pinWrite(1);

    gpioDelay(5000000);

    diode.pinWrite(0);*/

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
    currentClient_->addResponse(make_shared<DataResponse>("Test_ok"));
}

void CommandHandlerVisitor::visit(BlindsStatusCommand &command)
{
    cout << "BlindsStatusCommand" << endl;

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
}

void CommandHandlerVisitor::visit(AutomaticBlindsCommand &command)
{
    cout << "AutomaticBlindsCommand" << endl;

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
}

void CommandHandlerVisitor::visit(TemperatureDemandCommand &command)
{
    cout << "TemperatureDemandCommand" << endl;

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
}

void CommandHandlerVisitor::visit(UserOutOfHomeCommand &command)
{
    cout << "UserOutOfHomeCommand" << endl;

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
}

void CommandHandlerVisitor::visit(EndConnectionCommand &command)
{
    cout << "EndConnectionCommand" << endl;

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
}

void CommandHandlerVisitor::visit(SnapshotCommand &command)
{
    cout << "SnapshotCommand" << endl;

    currentClient_->addResponse(make_shared<DataResponse>("OK"));
}

void CommandHandlerVisitor::initializeCurrentClient(ClientThreadTCP *client)
{
    currentClient_ = client;
}
