#include "GuardStatusCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

GuardStatusCommand::GuardStatusCommand()
        : Command(10, CommandType::GUARD_STATUS)
{}

GuardStatusCommand::~GuardStatusCommand()
{}

vector<uint8_t> GuardStatusCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

std::string GuardStatusCommand::getName()
{
    return string("GuardStatusCommand");
}

void GuardStatusCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void GuardStatusCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}
