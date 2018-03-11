#ifndef SAFEHOUSE_TEMPERATUREDEMANDBUILDER_H
#define SAFEHOUSE_TEMPERATUREDEMANDBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class TemperatureDemandBuilder final : public CommandBuilder
    {
    public:
        TemperatureDemandBuilder();
        ~TemperatureDemandBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}

#endif
