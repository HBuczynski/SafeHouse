#include "ServerTCP.h"

#include <protocol/Command.h>
#include <protocol/Response.h>
#include <packet/ListenStreamTCP.h>

#include <algorithm>


#include <iostream>

using namespace std;
using namespace utility;
using namespace communication;

ServerTCP::ServerTCP(uint16_t port,  uint8_t maxClientNumber)
        : port_(port),
          maxClientNumber_(maxClientNumber),
          runUserActivation_(false),
          logger_(Logger::getInstance())
{}

ServerTCP::~ServerTCP()
{
    stopUserActivation();
    stopDataListening();
}

void ServerTCP::startUserActivation()
{
    runUserActivation_ = true;

    activationThread_ = thread(&ServerTCP::activateUsers, this);
}

void ServerTCP::stopUserActivation()
{
    runUserActivation_ = false;

    if(activationThread_.joinable())
    {
        activationThread_.join();
    }
}

void ServerTCP::activateUsers()
{
    ListenStreamTCP serverSocket(port_);

    serverSocket.listenUsers(maxClientNumber_);
    uint32_t clientID = 1;

    if(logger_.isInformationEnable())
    {
        const string message = string("ServerTCP :: Server starts user acceptance.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    while(runUserActivation_)
    {
        updateClientList();

        if(clientList_.size() < maxClientNumber_)
        {
            //Wait on new users.
            auto client = make_unique<ClientThreadTCP>(move(serverSocket.acceptUsers()));

            if(logger_.isInformationEnable())
            {
                const string message = string("ServerTCP :: Client with ID -") + to_string(clientID) + string("- was registered.");
                logger_.writeLog(LogType::INFORMATION_LOG, message);
            }
            client->setID(clientID);
            client->startListen();

            //Assign new client_tcp to the vector.
            clientList_.push_back(move(client));
            ++clientID;
        }
    }
}

void ServerTCP::updateClientList()
{
    bool isSuccess = false;

    for(auto iter = clientList_.begin(); (iter != clientList_.end()) & !isSuccess; ++iter)
    {
        if(!(*iter)->checkListenEnable())
        {
            clientList_.erase(iter);
            isSuccess = true;
        }
    }
}

void ServerTCP::stopDataListening()
{
    for(auto iter = clientList_.begin(); iter != clientList_.end(); ++iter)
    {
        (*iter)->stopListen();
        clientList_.erase(iter);
    }
}
