#ifndef CLIENTTHREADTCP_H
#define CLIENTTHREADTCP_H

#include <packet/SendStreamTCP.h>
#include <protocol/CommandFactory.h>
#include <main_rpi/server_tcp/CommandHandlerVisitor.h>
#include <logger/Logger.h>

#include <thread>
#include <atomic>
#include <memory>

namespace communication
{
    class ClientThreadTCP
    {
    public:
        ClientThreadTCP(std::unique_ptr<SendStreamTCP> socket);
        ~ClientThreadTCP();

       void initializeCommandHandler();

        void startListen();
        void stopListen();
        bool checkListenEnable();

        void setID(uint32_t id);
        uint32_t getID() const;

    private:
        void runListen();

        std::atomic<bool> runListenThread_;
        std::thread listenThread_;

        std::unique_ptr<SendStreamTCP> socket_;
        uint32_t id_;

        CommandFactory commandFactory_;
        CommandHandlerVisitor commandHandler_;

        utility::Logger& logger_;

    };
}
#endif
