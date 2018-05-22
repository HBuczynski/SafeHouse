#ifndef AHRS_BLACK_BOX_COMMANDHANDLER_H
#define AHRS_BLACK_BOX_COMMANDHANDLER_H

#include <logger/Logger.h>
#include <protocol/CommandVisitor.h>
#include <protocol/Response.h>
#include <peripherals/PeriphManager.h>

#include <memory>
#include <queue>

namespace communication
{
    class ClientThreadTCP;

    class CommandHandlerVisitor final : public CommandVisitor
    {
    public:
        CommandHandlerVisitor();
        ~CommandHandlerVisitor();

        virtual void visit(BlindsDOWNOnTimeCommand& command) override;
        virtual void visit(BlindsUPOnTimeCommand& command) override;
        virtual void visit(BlindsUPCommand& command) override;
        virtual void visit(BlindsDOWNCommand& command) override;
        virtual void visit(BlindsStatusCommand& command) override;
        virtual void visit(AutomaticBlindsCommand& command) override;
        virtual void visit(TemperatureDemandCommand& command) override;
        virtual void visit(UserOutOfHomeCommand& command) override;
        virtual void visit(EndConnectionCommand& command) override;
        virtual void visit(SnapshotCommand& command) override;

        void initializeCurrentClient(ClientThreadTCP *client);

    private:
        ClientThreadTCP *currentClient_;

        utility::Logger& logger_;
        peripherials::PeriphManager &periphManager_;
    };
}
#endif