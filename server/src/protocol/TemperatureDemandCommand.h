#ifndef SAFEHOUSE_TEMPERATUREDEMAND_H
#define SAFEHOUSE_TEMPERATUREDEMAND_H

#include "Command.h"

namespace communication
{
    class TemperatureDemandCommand final : public Command
    {
    public:
        TemperatureDemandCommand();
        ~TemperatureDemandCommand();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor& visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}

#endif
