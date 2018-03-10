#include "CommunicationManagerRpi.h"

#include <iostream>

using namespace std;
using namespace communication;

CommunicationManagerRpi::CommunicationManagerRpi(uint16_t serverPort, uint8_t maxUserNumber)
{
    server_ = make_shared<ServerTCP>(serverPort, maxUserNumber);
}

CommunicationManagerRpi::~CommunicationManagerRpi()
{
}


void CommunicationManagerRpi::initialize()
{
    activateServer();
}

void CommunicationManagerRpi::activateServer()
{
    server_->startUserActivation();
}




