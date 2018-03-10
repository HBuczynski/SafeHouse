#ifndef BLINDS_UP_ON_TIME_COMMAND_H
#define BLINDS_UP_ON_TIME_COMMAND_H

#include "Command.h"

namespace communication
{
    class BlindsUPOnTimeCommand final : public Command
    {
    public:
        BlindsUPOnTimeCommand(uint32_t epochTime);
        ~BlindsUPOnTimeCommand();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor& visitor) override;

        void setEpochDateAndTime(uint32_t dateAndTime);
        uint32_t getEpochDateAndTime() const;

    private:
        virtual void initializeDataSize() override;

        uint32_t epochTime_;
    };
}

#endif

