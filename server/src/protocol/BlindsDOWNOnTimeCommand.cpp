#include "BlindsDOWNOnTimeCommand.h"
#include "CommandVisitor.h"

#include <utility/BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;


BlindsDOWNOnTimeCommand::BlindsDOWNOnTimeCommand(uint32_t epochTime)
        : Command(10, CommandType::BLINDS_DOWN_ON_TIME),
          epochTime_(epochTime)
{
}

BlindsDOWNOnTimeCommand::~BlindsDOWNOnTimeCommand()
{
}

vector<uint8_t> BlindsDOWNOnTimeCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    BytesConverter::appendUINT32toVectorOfUINT8(epochTime_, frame);

    return frame;
}

string BlindsDOWNOnTimeCommand::getName()
{
    return string("BlindsDOWNOnTimeCommand");
}

void BlindsDOWNOnTimeCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void BlindsDOWNOnTimeCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);
    dataSize += sizeof(epochTime_);

    setDataSize(dataSize);
}

void BlindsDOWNOnTimeCommand::setEpochDateAndTime(uint32_t dateAndTime)
{
    epochTime_ = dateAndTime;
}

uint32_t BlindsDOWNOnTimeCommand::getEpochDateAndTime() const
{
    return epochTime_;
}


