#ifndef SAFEHOUSE_GUARDSTATUSBUILDER_H
#define SAFEHOUSE_GUARDSTATUSBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class GuardStatusBuilder final : public CommandBuilder
    {
    public:
        GuardStatusBuilder();
        ~GuardStatusBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}

#endif