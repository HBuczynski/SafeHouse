#ifndef BLINDS_DOWN_BUILDER_H
#define BLINDS_DOWN_BUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class BlindsDOWNBuilder final : public CommandBuilder
    {
    public:
        BlindsDOWNBuilder();
        ~BlindsDOWNBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}
#endif
