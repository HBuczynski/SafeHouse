#ifndef BLINDS_STATUS_BUILDER_H
#define BLINDS_STATUS_BUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class BlindsStatusBuilder final : public CommandBuilder
    {
    public:
        BlindsStatusBuilder();
        ~BlindsStatusBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;

    };
}

#endif