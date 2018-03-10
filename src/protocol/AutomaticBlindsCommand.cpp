#include "AutomaticBlindsCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

AutomaticBlindsCommand::AutomaticBlindsCommand()
    : Command(10, CommandType::AUTOMATIC_BLINDS)
{}

AutomaticBlindsCommand::~AutomaticBlindsCommand()
{}

std::vector<uint8_t> AutomaticBlindsCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

std::string AutomaticBlindsCommand::getName()
{
    return string("BlindsStatusCommand");
}

void AutomaticBlindsCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void AutomaticBlindsCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}
