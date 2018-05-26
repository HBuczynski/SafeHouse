#ifndef AHRS_BLACK_BOX_COMMANDHANDLER_H
#define AHRS_BLACK_BOX_COMMANDHANDLER_H

#include <logger/Logger.h>
#include <protocol/CommandVisitor.h>
#include <protocol/Response.h>
#include <peripherals/PeriphManager.h>

#include <cstdint>
#include <spawn.h>
#include <cstdint>
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
        virtual void visit(StartStreamCommand& command) override;
        virtual void visit(StopStreamCommand& command) override;

        void initializeCurrentClient(ClientThreadTCP *client);

    private:
        static void startStream();
        static void stopStream();

        static void waitOnProcess();

        ClientThreadTCP *currentClient_;

        static posix_spawn_file_actions_t action_;
        static pid_t pid_;

        static utility::Logger& logger_;
        peripherials::PeriphManager &periphManager_;

        static const std::string STREAM_SCRIPT_PATH;
        static const std::string STREAM_SCRIPT_NAME;
    };
}
#endif
