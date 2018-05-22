#ifndef BLINDS_UP_BUILDER_H
#define BLINDS_UP_BUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class BlindsUPBuilder final : public CommandBuilder
    {
    public:
        BlindsUPBuilder();
        ~BlindsUPBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;

    private:
        const uint16_t INIT_DATA_POSITION_IN_FRAME = 6;
    };
}

#endif