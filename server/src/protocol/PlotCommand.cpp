#include "PlotCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

PlotCommand::PlotCommand(const ParameterType parameterType, const SensorTagType sensorTagType)
        : Command(10, CommandType::PLOT),
          parameterType_(parameterType),
          sensorTagType_(sensorTagType)
{}

PlotCommand::~PlotCommand()
{}

vector<uint8_t> PlotCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));
    frame.push_back(static_cast<uint8_t>(parameterType_));
    frame.push_back(static_cast<uint8_t>(sensorTagType_));

    return frame;
}

std::string PlotCommand::getName()
{
    return string("PlotCommand");
}

void PlotCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void PlotCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);
    dataSize += sizeof(parameterType_);
    dataSize += sizeof(sensorTagType_);

    setDataSize(dataSize);
}

ParameterType PlotCommand::getParameterType() const
{
    return parameterType_;
}

void PlotCommand::setParameterType(ParameterType parameterType)
{
    parameterType_ = parameterType;
}

SensorTagType PlotCommand::getSensorTagType() const
{
    return sensorTagType_;
}

void PlotCommand::setSensorTagType(SensorTagType sensorTagType)
{
    sensorTagType_ = sensorTagType;
}