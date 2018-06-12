#ifndef SAFEHOUSE_MOTORSTATUCOmmandSBUILDER_H
#define SAFEHOUSE_MOTORSTATUCOmmandSBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class MotorStatusCommandBuilder final : public CommandBuilder
    {
    public:
        MotorStatusCommandBuilder();
        ~MotorStatusCommandBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}

#endif