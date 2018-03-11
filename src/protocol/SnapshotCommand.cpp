#include "SnapshotCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

SnapshotCommand::SnapshotCommand()
        : Command(10, CommandType::SNAPSHOT)
{}

SnapshotCommand::~SnapshotCommand()
{}

vector<uint8_t> SnapshotCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

std::string SnapshotCommand::getName()
{
    return string("SnapshotCommand");
}

void SnapshotCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void SnapshotCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}
