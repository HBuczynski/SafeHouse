#ifndef SAFEHOUSE_USEROUTOFHOMECOMMAND_H
#define SAFEHOUSE_USEROUTOFHOMECOMMAND_H

#include "Command.h"

namespace communication
{
    class UserOutOfHomeCommand final : public Command
    {
    public:
        UserOutOfHomeCommand();
        ~UserOutOfHomeCommand();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor &visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}
#endif
