#ifndef SAFEHOUSE_GUARDSTATUSCOMMAND_H
#define SAFEHOUSE_GUARDSTATUSCOMMAND_H

#include "Command.h"

namespace communication
{
    class GuardStatusCommand final : public Command
    {
    public:
        GuardStatusCommand();
        ~GuardStatusCommand();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor &visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}

#endif
