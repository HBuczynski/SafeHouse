#ifndef SAFEHOUSE_AUTOMATICBLINDSBUILDER_H
#define SAFEHOUSE_AUTOMATICBLINDSBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class AutomaticBlindsBuilder final : public CommandBuilder
    {
    public:
        AutomaticBlindsBuilder();
        ~AutomaticBlindsBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;

    };
}

#endif //SAFEHOUSE_AUTOMATICBLINDSBUILDER_H
