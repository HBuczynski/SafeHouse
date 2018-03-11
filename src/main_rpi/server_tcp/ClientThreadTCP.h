#ifndef CLIENTTHREADTCP_H
#define CLIENTTHREADTCP_H

#include <packet/SendStreamTCP.h>
#include <protocol/CommandFactory.h>
#include <main_rpi/server_tcp/CommandHandlerVisitor.h>
#include <logger/Logger.h>

#include <thread>
#include <atomic>
#include <memory>
#include <queue>

namespace communication
{
    class ClientThreadTCP
    {
    public:
        ClientThreadTCP(std::unique_ptr<SendStreamTCP> socket);
        ~ClientThreadTCP();

        void initializeCommandHandler();

        void addResponse(std::shared_ptr<communication::Response> response);

        void startSendAndListen();
        void stopSendAndListen();
        bool checkListenEnable();

        void setID(uint32_t id);
        uint32_t getID() const;

    private:
        void runListen();
        void runSend();

        std::atomic<bool> runListenThread_;
        std::atomic<bool> runSendThread_;
        std::thread listenThread_;
        std::thread sendThread_;

        std::mutex queueMutex_;
        std::queue<std::shared_ptr<communication::Response>> responseQueue_;
        std::unique_ptr<SendStreamTCP> socket_;
        uint32_t id_;

        CommandFactory commandFactory_;
        CommandHandlerVisitor commandHandler_;

        utility::Logger& logger_;

    };
}
#endif
