#ifndef BLINDS_DOWN_COMMAND_H
#define BLINDS_DOWN_COMMAND_H

#include "Command.h"

namespace communication
{
    class BlindsDOWNCommand : public Command
    {
    public:
        BlindsDOWNCommand();
        ~BlindsDOWNCommand();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor& visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}

#endif
