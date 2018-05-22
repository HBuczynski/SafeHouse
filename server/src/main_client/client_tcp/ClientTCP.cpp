#include "ClientTCP.h"

#include <iostream>

using namespace std;
using namespace utility;
using namespace communication;

ClientTCP::ClientTCP(uint16_t portIn, string addressIn)
    : port_(portIn),
      address_(addressIn),
      executeCommandsFlag_(false),
      executeResponsesFlag_(false),
      logger_(Logger::getInstance())
{}

ClientTCP::~ClientTCP()
{
    stopCommandListeningAndSending();
}

void ClientTCP::connectToServer()
{
    socket_ = make_unique<SendStreamTCP>(port_, address_);
    try
    {
        socket_->connectToServer();
    }
    catch (exception &e)
    {
        if(logger_.isErrorEnable())
        {
            const string message =
                    string("ClienTCP :: Client data: ") + address_ + string(" and port: ") + to_string(port_) +
                    string("-. Received exception: ") + e.what();
            logger_.writeLog(LogType::ERROR_LOG, message);
        }
    }
}

void ClientTCP::startCommandListeningAndSending()
{
    executeCommandsFlag_ = true;
    executeResponsesFlag_ = true;

    queue<std::unique_ptr<Command>> emptyCommandQueue;

    // Clear elements in queue.
    commandQueue_.swap(emptyCommandQueue);

    // In case if the preious connection was finished and there is no certainty that previous thread was joined.
    if(executeCommandThread_.joinable())
    {
        executeCommandThread_.join();
    }

    executeCommandThread_ = thread(&ClientTCP::executeCommands, this);
    executeResponsesThread_ = thread(&ClientTCP::executeResponses, this);
}

void ClientTCP::stopCommandListeningAndSending()
{
    if(executeCommandsFlag_)
    {
        executeCommandsFlag_ = false;

        socket_->closeSocket();

        if(executeCommandThread_.joinable())
        {
            executeCommandThread_.join();
        }
    }

    if(executeResponsesFlag_)
    {
        executeResponsesFlag_ = false;

        if(executeResponsesThread_.joinable())
        {
            executeResponsesThread_.join();
        }
    }
}

void ClientTCP::sendCommand(unique_ptr<Command> command)
{
    lock_guard<mutex> lock(commandQueueMutex_);
    commandQueue_.push(move(command));
}

bool ClientTCP::isCommandQueueEmpty()
{
    lock_guard<mutex> lock(commandQueueMutex_);
    return commandQueue_.empty();
}

unique_ptr<Command> ClientTCP::getFromCommandQueue()
{
    lock_guard<mutex> lock(commandQueueMutex_);

    auto command = move(commandQueue_.front());
    commandQueue_.pop();

    return command;
}

void ClientTCP::executeResponses()
{
    while(executeResponsesFlag_)
    {
        try
        {
            const auto responseFrame = socket_->receivePacket();

            unique_ptr<Response> response = responseFactory_.createCommand(responseFrame);
            response->accept(responseHandler_);

            if(logger_.isInformationEnable())
            {
                const string message = string("ClientTCP :: Client data: ") + address_ + string(" and port: ") +
                                       to_string(port_) + string(". Received response: ") +
                                       response->getName();
                logger_.writeLog(LogType::INFORMATION_LOG, message);
            }
        }
        catch(exception &e)
        {
            catchExceptions(e.what());

            stopCommandListeningAndSending();
        }
    }
}

void ClientTCP::executeCommands()
{
    while (executeCommandsFlag_)
    {
        if(!isCommandQueueEmpty())
        {
            const auto command = getFromCommandQueue();

            try
            {
                socket_->sendData(command->getFrameBytes());

                if(logger_.isInformationEnable())
                {
                    const string message = string("ClientTCP :: Client data: ") + address_ + string(" and port: ") +
                                           to_string(port_) + string(". Send command: ") + command->getName();
                    logger_.writeLog(LogType::INFORMATION_LOG, message);
                }
            }
            catch (exception &e)
            {
                catchExceptions(e.what());
            }
        }
    }
}

void ClientTCP::catchExceptions(string exception)
{
    if(logger_.isErrorEnable())
    {
        const string message = string("ClientTCP :: Client data: ") + address_ + string(" and port: ") +
                               to_string(port_) + string("Exception: ") + exception;
                logger_.writeLog(LogType::ERROR_LOG, message);
    }
}