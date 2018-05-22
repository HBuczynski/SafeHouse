#ifndef BLINDS_STATUS_COMMAND_H
#define BLINDS_STATUS_COMMAND_H

#include "Command.h"
#include <string>

namespace communication
{
    class BlindsStatusCommand : public Command
    {
    public:
        BlindsStatusCommand();
        ~BlindsStatusCommand();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor& visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}
#endif
