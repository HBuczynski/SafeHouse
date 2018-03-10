#include "ClientThreadTCP.h"

#include <protocol/Command.h>

#include <iostream>

using namespace std;
using namespace utility;
using namespace communication;

ClientThreadTCP::ClientThreadTCP(unique_ptr<SendStreamTCP> socket)
    : runListenThread_(false),
      socket_(std::move(socket)),
      logger_(Logger::getInstance())
{
    initializeCommandHandler();
}

ClientThreadTCP::~ClientThreadTCP()
{
    stopListen();
}

void ClientThreadTCP::initializeCommandHandler()
{
    commandHandler_.initializeCurrentClient(this);
}

void ClientThreadTCP::setID(uint32_t id)
{
    id_ = id;
}

uint32_t ClientThreadTCP::getID() const
{
    return id_;
}

void ClientThreadTCP::startListen()
{
    runListenThread_ = true;
    listenThread_ = thread(&ClientThreadTCP::runListen, this);
}

void ClientThreadTCP::stopListen()
{
    socket_->closeSocket();

    runListenThread_ = false;

    if(listenThread_.joinable())
    {
        listenThread_.join();
    }
}

void ClientThreadTCP::runListen()
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ClientThreadTCP :: ClientdID -") + to_string(getID()) + string("- starts listening.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    // to do: zamkniecie gdy nie otrzymamy pakietu
    while(runListenThread_)
    {
        try
        {
            const auto frame = socket_->receivePacket();

            const auto command = commandFactory_.createCommand(frame);
            command->accept(commandHandler_);

            const auto response = commandHandler_.getResponse();
            socket_->sendData(response->getFrameBytes());
        }
        catch (exception &e)
        {
            // Factory can't create a command
            if(logger_.isErrorEnable() && runListenThread_)
            {
                const string message = string("ClientThreadTCP :: ClientdID -") + to_string(getID()) +
                                 string("-. Received exception: ") + e.what();
                logger_.writeLog(LogType::ERROR_LOG, message);
            }

            if(string(e.what()) ==  string("Received exception: Cannot receive packet.") )
            {
                runListenThread_ = false;
                socket_->closeSocket();
            }

            // // If socket has been closed or the connection has been lost, the thread has to be closed.
            if(!runListenThread_)
            {
                runListenThread_ = false;

                if(logger_.isWarningEnable())
                {
                    const string message = string("ClientThreadTCP :: ClientdID -") + to_string(getID()) +
                                           string("-. Connection was ended.");
                    logger_.writeLog(LogType::WARNING_LOG, message);
                }
            }
        }
    }
}

bool ClientThreadTCP::checkListenEnable()
{
    return runListenThread_;
}
