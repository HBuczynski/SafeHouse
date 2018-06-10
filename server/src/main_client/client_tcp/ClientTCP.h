#ifndef CLIENT_TCP_H
#define CLIENT_TCP_H

#include <main_client/client_tcp/ResponseHandlerVisitor.h>
#include <logger/Logger.h>
#include <packet/SendStreamTCP.h>
#include <protocol/Command.h>
#include <protocol/ResponseFactory.h>

#include <cstdint>
#include <atomic>
#include <string>
#include <memory>
#include <utility>
#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>

namespace communication
{
    class ClientTCP
    {
    public:
        ClientTCP(uint16_t portIn, std::string addressIn);
        ~ClientTCP();

        void connectToServer();

        void stopCommandListeningAndSending();
        void startCommandListeningAndSending();

        void sendCommand(std::unique_ptr<Command> command);

    private:
        bool isCommandQueueEmpty();
        std::unique_ptr<Command> getFromCommandQueue();

        void executeCommands();
        void executeResponses();
        void catchExceptions(std::string exception);

        uint16_t port_;
        std::string address_;

        std::unique_ptr<SendStreamTCP> socket_;

        std::atomic<bool> executeCommandsFlag_;
        std::thread executeCommandThread_;

        std::atomic<bool> executeResponsesFlag_;
        std::thread executeResponsesThread_;

        std::mutex commandQueueMutex_;
        std::queue<std::unique_ptr<Command>> commandQueue_;

        ResponseHandlerVisitor responseHandler_;
        ResponseFactory responseFactory_;

        utility::Logger& logger_;
    };

}
#endif
