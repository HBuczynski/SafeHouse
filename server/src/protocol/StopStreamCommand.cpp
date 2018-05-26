#include "StopStreamCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

StopStreamCommand::StopStreamCommand()
        : Command(10, CommandType::STOP_STREAM)
{}

StopStreamCommand::~StopStreamCommand()
{}

vector<uint8_t> StopStreamCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

std::string StopStreamCommand::getName()
{
    return string("StopStreamCommand");
}

void StopStreamCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void StopStreamCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}