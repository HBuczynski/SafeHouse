#ifndef SAFEHOUSE_SENSORTAGSAMPLESCOMMAND_H
#define SAFEHOUSE_SENSORTAGSAMPLESCOMMAND_H

#include "Command.h"

namespace communication
{
    class SensorTagSamplesCommand final : public Command
    {
    public:
        SensorTagSamplesCommand();
        ~SensorTagSamplesCommand();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor &visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}

#endif