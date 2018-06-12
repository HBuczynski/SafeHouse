#ifndef SAFEHOUSE_MOTORSTATUSBUILDER_H
#define SAFEHOUSE_MOTORSTATUSBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class MotorStatusBuilder final : public CommandBuilder
    {
    public:
        MotorStatusBuilder();
        ~MotorStatusBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}

#endif