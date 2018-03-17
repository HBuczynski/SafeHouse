#ifndef WAIC_SERVER_H
#define WAIC_SERVER_H

#include <protocol/Command.h>
#include <logger/Logger.h>

#include "CommandHandlerVisitor.h"
#include "ClientThreadTCP.h"

#include <map>
#include <list>
#include <atomic>
#include <memory>
#include <utility>
#include <thread>

namespace communication
{
    class ServerTCP
    {
    public:
        ServerTCP(uint16_t port, uint8_t maxClientNumber);
        ~ServerTCP();

        void startUserActivation();
        void stopUserActivation();
        void stopDataListening();

    private:
        typedef void (*sighandler_t)(int);

        void initializeTimer();
        void activateUsers();
        static void updateClientList();

        static void sendBroadcast(int);
        static void addClientTCPtoList(std::unique_ptr<ClientThreadTCP> client);
        static uint32_t clientListSize();

        uint16_t port_;
        uint8_t maxClientNumber_;

        std::atomic<bool> runUserActivation_;
        std::thread activationThread_;

        static std::mutex clienListMutex_;
        static std::list<std::unique_ptr<ClientThreadTCP> > clientList_;

        static utility::Logger& logger_;
    };
}
#endif
