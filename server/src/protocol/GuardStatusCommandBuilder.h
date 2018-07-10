#ifndef SAFEHOUSE_GUARDSTATUSCOMMANDBUILDER_H
#define SAFEHOUSE_GUARDSTATUSCOMMANDBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class GuardStatusCommandBuilder final : public CommandBuilder
    {
    public:
        GuardStatusCommandBuilder();
        ~GuardStatusCommandBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}

#endif