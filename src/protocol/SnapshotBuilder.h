#ifndef SAFEHOUSE_SNAPSHOTBUILDER_H
#define SAFEHOUSE_SNAPSHOTBUILDER_H

#include "CommandBuilder.h"

namespace communication
{
    class SnapshotBuilder final : public CommandBuilder
    {
    public:
        SnapshotBuilder();
        ~SnapshotBuilder();

        std::unique_ptr<Command> create(const std::vector<uint8_t> &commandInBytes) override;
    };
}

#endif