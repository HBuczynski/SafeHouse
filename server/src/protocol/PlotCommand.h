#ifndef SAFEHOUSE_PLOTCOMMAND_H
#define SAFEHOUSE_PLOTCOMMAND_H

#include "Command.h"

namespace communication
{
    enum class ParameterType : uint8_t
    {
        TEMPERATURE = 10,
        HUMIDITY = 20,
        LUMINACIA = 30
    };

    enum class SensorTagType : uint8_t
    {
        FIRST = 10,
        SECOND = 20,
        THIRD = 30,
        ALL = 40
    };


    class PlotCommand final : public Command
    {
    public:
        PlotCommand(const ParameterType parameterType, const SensorTagType sensorTagType);
        ~PlotCommand();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor &visitor) override;

        ParameterType getParameterType() const;
        void setParameterType(ParameterType parameterType);

        SensorTagType getSensorTagType() const;
        void setSensorTagType(SensorTagType sensorTagType);

    private:
        virtual void initializeDataSize() override;

        ParameterType parameterType_;
        SensorTagType sensorTagType_;
    };
}



#endif