#ifndef SAFEHOUSE_USEROUTOFHOMEBUILDER_H
#define SAFEHOUSE_USEROUTOFHOMEBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class UserOutOfHomeBuilder final : public CommandBuilder
    {
    public:
        UserOutOfHomeBuilder();
        ~UserOutOfHomeBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}
#endif
