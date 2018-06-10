#ifndef SAFEHOUSE_AUTOMATICBLINDSCOMMAND_H
#define SAFEHOUSE_AUTOMATICBLINDSCOMMAND_H

#include <Command.h>

namespace communication
{
    class AutomaticBlindsCommand final : public Command
    {
    public:
        AutomaticBlindsCommand();
        ~AutomaticBlindsCommand();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor& visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}

#endif //SAFEHOUSE_AUTOMATICBLINDSCOMMAND_H
