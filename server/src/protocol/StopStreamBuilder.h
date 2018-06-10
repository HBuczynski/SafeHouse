#ifndef SAFEHOUSE_STOPSTREAMBUILDER_H
#define SAFEHOUSE_STOPSTREAMBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class StopStreamBuilder final : public CommandBuilder
    {
    public:
        StopStreamBuilder();
        ~StopStreamBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}


#endif //SAFEHOUSE_STOPSTREAMBUILDER_H
