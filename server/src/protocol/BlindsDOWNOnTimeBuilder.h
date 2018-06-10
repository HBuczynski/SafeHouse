#ifndef BLINDS_DOWN_ON_TIME_BUILDER_H
#define BLINDS_DOWN_ON_TIME_BUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class BlindsDOWNOnTimeBuilder final : public CommandBuilder
    {
    public:
        BlindsDOWNOnTimeBuilder();
        ~BlindsDOWNOnTimeBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;

    private:
        const uint16_t INIT_EPOCH_TIME_POSITION_IN_FRAME = 6;
    };
}
#endif
