#ifndef COMMUNICATION_MANAGER_H
#define COMMUNICATION_MANAGER_H

#include <main_client/client_tcp/ClientTCP.h>

#include <memory>
#include <list>
#include <utility>
#include <mutex>
#include <memory>
#include <string>

namespace communication
{
    struct CommunicationParameters
    {
        uint16_t destinationPortTCP;
        std::string destinationAddressTCP;
    };

    class CommunicationManagerClient
    {
    public:
        CommunicationManagerClient(CommunicationParameters parameters);
        ~CommunicationManagerClient();

        void initializeClientConnection();

        // Only for testing purposes.
        void sendCommands();

    private:
        CommunicationParameters parameters_;

        std::unique_ptr<ClientTCP> client_;
    };
}
#endif
