#ifndef SAFEHOUSE_USERINHOMEBUILDER_H
#define SAFEHOUSE_USERINHOMEBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class UserInHomeBuilder final : public CommandBuilder
    {
    public:
        UserInHomeBuilder();
        ~UserInHomeBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}
#endif
