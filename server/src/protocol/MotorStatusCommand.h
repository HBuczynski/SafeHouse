#ifndef SAFEHOUSE_MOTORSTATUSCOMMAND_H
#define SAFEHOUSE_MOTORSTATUSCOMMAND_H

#include "Command.h"

namespace communication
{
    class MotorStatusCommand final : public Command
    {
    public:
        MotorStatusCommand();
        ~MotorStatusCommand();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor &visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}

#endif
