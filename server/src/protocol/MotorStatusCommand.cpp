#include "MotorStatusCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

MotorStatusCommand::MotorStatusCommand()
        : Command(10, CommandType::MOTOR_STATUS_COMMAND)
{}

MotorStatusCommand::~MotorStatusCommand()
{}

vector<uint8_t> MotorStatusCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

std::string MotorStatusCommand::getName()
{
    return string("MotorStatusCommand");
}

void MotorStatusCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void MotorStatusCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}
