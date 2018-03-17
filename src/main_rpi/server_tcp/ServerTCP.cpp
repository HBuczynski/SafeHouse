#include "ServerTCP.h"

#include <signal.h>
#include <sys/time.h>

#include <protocol/AuthenticateResponse.h>
#include <packet/ListenStreamTCP.h>

#include <algorithm>


#include <iostream>

using namespace std;
using namespace utility;
using namespace peripherials;
using namespace communication;

list<unique_ptr<ClientThreadTCP> > ServerTCP::clientList_;
utility::Logger& ServerTCP::logger_ = Logger::getInstance();
mutex ServerTCP::clienListMutex_;

ServerTCP::ServerTCP(uint16_t port,  uint8_t maxClientNumber)
        : port_(port),
          maxClientNumber_(maxClientNumber),
          runUserActivation_(false),
          periphManager_(PeriphManager::getInstance())
{
    function<void(shared_ptr<communication::Response>)> callback = [](shared_ptr<communication::Response> response){ServerTCP::sendBroadcast(response);};
    periphManager_.initBroadcastFucntion(callback);
}

ServerTCP::~ServerTCP()
{
    stopUserActivation();
    stopDataListening();
}

void ServerTCP::startUserActivation()
{
    runUserActivation_ = true;

    activationThread_ = thread(&ServerTCP::activateUsers, this);
    initializeTimer();
}

void ServerTCP::initializeTimer()
{
    struct timeval my_value={10,0};
    struct timeval my_interval={10,0};
    struct itimerval my_timer={my_interval,my_value};

    setitimer(ITIMER_REAL, &my_timer, 0);
    signal(SIGALRM, (sighandler_t) sendBroadcast);
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
    unique_ptr<ListenStreamTCP> serverSocket;

    try
    {
        serverSocket = make_unique<ListenStreamTCP>(port_);
    }
    catch (exception &e)
    {
        if(logger_.isErrorEnable())
        {
            const string message =
                    string("ServerTCP :: ") + string("-. Received exception: ") + e.what();
            logger_.writeLog(LogType::ERROR_LOG, message);
        }
    }

    serverSocket->listenUsers(maxClientNumber_);
    uint32_t clientID = 1;

    if(logger_.isInformationEnable())
    {
        const string message = string("ServerTCP :: Server starts user acceptance.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    while(runUserActivation_)
    {
        updateClientList();

        if(clientListSize() < maxClientNumber_)
        {
            //Wait on new users.
            auto client = make_unique<ClientThreadTCP>(move(serverSocket->acceptUsers()));

            if(logger_.isInformationEnable())
            {
                const string message = string("ServerTCP :: Client with ID -") + to_string(clientID) + string("- was registered.");
                logger_.writeLog(LogType::INFORMATION_LOG, message);
            }
            client->setID(clientID);
            client->startSendAndListen();

            //Assign new client_tcp to the vector.
            addClientTCPtoList(move(client));
            ++clientID;
        }
    }
}

void ServerTCP::updateClientList()
{
    bool isSuccess = false;

    lock_guard<mutex> lock(clienListMutex_);
    for(auto iter = clientList_.begin(); (iter != clientList_.end()) & !isSuccess; ++iter)
    {
        if(!(*iter)->checkListenEnable())
        {
            if(logger_.isInformationEnable())
            {
                const string message = string("ServerTCP :: Server stop listening user ID: ") + to_string((*iter)->getID());
                logger_.writeLog(LogType::INFORMATION_LOG, message);
            }

            clientList_.erase(iter);
            isSuccess = true;
        }
    }
}

void ServerTCP::sendBroadcast(int)
{
    ServerTCP::updateClientList();

    lock_guard<mutex> lock(clienListMutex_);
    for(auto iter = clientList_.begin(); iter != clientList_.end(); ++iter)
    {
        (*iter)->addResponse(make_shared<AuthenticateResponse>());
    }
}

void ServerTCP::stopDataListening()
{
    lock_guard<mutex> lock(clienListMutex_);
    for(auto iter = clientList_.begin(); iter != clientList_.end(); ++iter)
    {
        (*iter)->stopSendAndListen();
        clientList_.erase(iter);
    }
}

void ServerTCP::addClientTCPtoList(std::unique_ptr<ClientThreadTCP> client)
{
    lock_guard<mutex> lock(clienListMutex_);
    clientList_.push_back(move(client));
}

uint32_t ServerTCP::clientListSize()
{
    lock_guard<mutex> lock(clienListMutex_);
    return clientList_.size();
}

void ServerTCP::sendBroadcast(std::shared_ptr<communication::Response> response)
{
    ServerTCP::updateClientList();

    lock_guard<mutex> lock(clienListMutex_);
    for(auto iter = clientList_.begin(); iter != clientList_.end(); ++iter)
    {
        (*iter)->addResponse(response);
    }
}
