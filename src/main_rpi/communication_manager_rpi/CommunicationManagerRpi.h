#ifndef COMMUNICATION_MANAGER_RPI_H
#define COMMUNICATION_MANAGER_RPI_H

#include <main_rpi/server_tcp/ServerTCP.h>

#include <memory>
#include <list>
#include <utility>
#include <mutex>

namespace communication
{
    class CommunicationManagerFeeder
    {
    public:
        CommunicationManagerFeeder(uint16_t serverPort, uint8_t maxUserNumber);
        ~CommunicationManagerFeeder();

        void initialize();

    private:
        void activateServer();

        std::shared_ptr<ServerTCP> server_;
    };
}
#endif
