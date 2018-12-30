#include "SensorTagSamplesCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

SensorTagSamplesCommand::SensorTagSamplesCommand()
        : Command(10, CommandType::SENSOR_TAG_SAMPLES)
{}

SensorTagSamplesCommand::~SensorTagSamplesCommand()
{}

vector<uint8_t> SensorTagSamplesCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

std::string SensorTagSamplesCommand::getName()
{
    return string("SensorTagSamplesCommand");
}

void SensorTagSamplesCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void SensorTagSamplesCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}