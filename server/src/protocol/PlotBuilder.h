#ifndef SAFEHOUSE_PLOTBUILDER_H
#define SAFEHOUSE_PLOTBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class PlotBuilder final : public CommandBuilder
    {
    public:
        PlotBuilder();
        ~PlotBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}


#endif