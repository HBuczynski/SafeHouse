#ifndef BLINDS_DOWN_ON_TIME_COMMAND_H
#define BLINDS_DOWN_ON_TIME_COMMAND_H

#include "Command.h"
#include <string>

namespace communication
{
    class BlindsDOWNOnTimeCommand final : public Command
    {
    public:
        BlindsDOWNOnTimeCommand(uint32_t epochTime);
        ~BlindsDOWNOnTimeCommand();

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