#ifndef SAFEHOUSE_STARTSTREAMBUILDER_H
#define SAFEHOUSE_STARTSTREAMBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class StartStreamBuilder final : public CommandBuilder
    {
    public:
        StartStreamBuilder();
        ~StartStreamBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}


#endif //SAFEHOUSE_STARTSTREAMBUILDER_H
