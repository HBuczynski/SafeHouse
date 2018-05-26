#include "StartStreamCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

StartStreamCommand::StartStreamCommand()
        : Command(10, CommandType::START_STREAM)
{}

StartStreamCommand::~StartStreamCommand()
{}

vector<uint8_t> StartStreamCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

std::string StartStreamCommand::getName()
{
    return string("StartStreamCommand");
}

void StartStreamCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void StartStreamCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}