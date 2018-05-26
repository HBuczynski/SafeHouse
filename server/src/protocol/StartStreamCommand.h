#ifndef SAFEHOUSE_STARTSTREAMCOMMAND_H
#define SAFEHOUSE_STARTSTREAMCOMMAND_H

#include "Command.h"

namespace communication
{
    class StartStreamCommand final : public Command
    {
    public:
        StartStreamCommand();
        ~StartStreamCommand();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor &visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}


#endif //SAFEHOUSE_STARTSTREAMCOMMAND_H
