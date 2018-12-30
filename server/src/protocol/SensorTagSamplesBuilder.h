#ifndef SAFEHOUSE_SENSORTAGSAMPLESBUILDER_H
#define SAFEHOUSE_SENSORTAGSAMPLESBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class SensorTagSamplesBuilder final : public CommandBuilder
    {
    public:
        SensorTagSamplesBuilder();
        ~SensorTagSamplesBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}

#endif