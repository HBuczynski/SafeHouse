#ifndef SAFEHOUSE_SNAPSHOTCOMMAND_H
#define SAFEHOUSE_SNAPSHOTCOMMAND_H

#include "Command.h"

namespace communication
{
    class SnapshotCommand final : public Command
    {
    public:
        SnapshotCommand();
        ~SnapshotCommand();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor &visitor) override;

    private:
        virtual void initializeDataSize() override;
    };
}

#endif
