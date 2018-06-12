#ifndef WAIC_COMMAND_H
#define WAIC_COMMAND_H

#include "Frame.h"

namespace communication
{
    class CommandVisitor;

    enum CommandType : uint8_t
    {
        BLINDS_UP = 5,
        BLINDS_DOWN = 10,
        BLINDS_UP_ON_TIME = 15,
        BLINDS_DOWN_ON_TIME = 20,
        BLINDS_STATUS = 25,
        AUTOMATIC_BLINDS = 30,
        TEMPERATURE_DEMAND = 35,
        USER_OUT_OF_HOME = 40,
		USER_IN_HOME = 41,
        SNAPSHOT = 45,
        END_CONNECTION = 50,
        START_STREAM = 60,
        STOP_STREAM = 70,
		MOTOR_STATUS = 71,
		GUARD_STATUS = 72
    };

    class Command : public Frame
    {
    public:
        Command(uint8_t dataSizeIn, CommandType commandTypeIn);
        virtual ~Command();

        virtual std::vector<uint8_t > getFrameBytes() = 0;
        virtual std::string getName() = 0;
        virtual void accept(CommandVisitor& visitor) = 0;

        const CommandType& getCommandType() const;

    protected:
        virtual void initializeDataSize() = 0;

        CommandType commandType_;

    };
}
#endif