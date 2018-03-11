#include "BlindsUPOnTimeCommand.h"
#include "CommandVisitor.h"

#include "BytesConverter.h"

using namespace std;
using namespace utility;
using namespace communication;

BlindsUPOnTimeCommand::BlindsUPOnTimeCommand(uint32_t epochTime)
        : Command(10, CommandType::BLINDS_UP_ON_TIME),
          epochTime_(epochTime)
{}

BlindsUPOnTimeCommand::~BlindsUPOnTimeCommand()
{}

vector<uint8_t> BlindsUPOnTimeCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    BytesConverter::appendUINT32toVectorOfUINT8(epochTime_, frame);

    return frame;
}

string BlindsUPOnTimeCommand::getName()
{
    return string("BlindsUPOnTimeCommand");
}

void BlindsUPOnTimeCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void BlindsUPOnTimeCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);
    dataSize += sizeof(epochTime_);

    setDataSize(dataSize);
}

void BlindsUPOnTimeCommand::setEpochDateAndTime(uint32_t dateAndTime)
{
    epochTime_ = dateAndTime;
}

uint32_t BlindsUPOnTimeCommand::getEpochDateAndTime() const
{
    return epochTime_;
}
