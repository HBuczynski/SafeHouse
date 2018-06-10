#ifndef SAFEHOUSE_STOPSTREAMCOMMAND_H
#define SAFEHOUSE_STOPSTREAMCOMMAND_H

#include "Command.h"

namespace communication
{
    class StopStreamCommand final : public Command
    {
    public:
        StopStreamCommand();
        ~StopStreamCommand();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor &visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}


#endif //SAFEHOUSE_STOPSTREAMCOMMAND_H
