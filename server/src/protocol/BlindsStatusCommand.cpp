#include "BlindsStatusCommand.h"
#include "CommandVisitor.h"

#include <utility/BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;

BlindsStatusCommand::BlindsStatusCommand()
    : Command(10, CommandType::BLINDS_STATUS)
{}

BlindsStatusCommand::~BlindsStatusCommand()
{}

vector<uint8_t> BlindsStatusCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

string BlindsStatusCommand::getName()
{
    return string("BlindsStatusCommand");
}

void BlindsStatusCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void BlindsStatusCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}
