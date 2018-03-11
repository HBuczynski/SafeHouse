#include "TemperatureDemandCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

TemperatureDemandCommand::TemperatureDemandCommand()
        : Command(10, CommandType::TEMPERATURE_DEMAND)
{}

TemperatureDemandCommand::~TemperatureDemandCommand()
{}

std::vector<uint8_t> TemperatureDemandCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

string TemperatureDemandCommand::getName()
{
    return string("TemperatureDemandCommand");
}

void TemperatureDemandCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void TemperatureDemandCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}
