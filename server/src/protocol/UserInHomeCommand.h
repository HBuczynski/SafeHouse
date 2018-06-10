#ifndef SAFEHOUSE_USERINHOMECOMMAND_H
#define SAFEHOUSE_USERINHOMECOMMAND_H

#include "Command.h"

namespace communication
{
    class UserInHomeCommand final : public Command
    {
    public:
        UserInHomeCommand();
        ~UserInHomeCommand();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor &visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}
#endif
