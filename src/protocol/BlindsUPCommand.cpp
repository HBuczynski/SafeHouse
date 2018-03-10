#include "BlindsUPCommand.h"
#include "CommandVisitor.h"
#include <utility/BytesConverter.h>

#include <stdexcept>

using namespace std;
using namespace utility;
using namespace communication;

BlindsUPCommand::BlindsUPCommand()
    : Command(10,CommandType::BLINDS_UP)
{}

BlindsUPCommand::~BlindsUPCommand()
{}

vector<uint8_t> BlindsUPCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

void BlindsUPCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}

string BlindsUPCommand::getName()
{
    return string("BlindsUPCommand");
}

void BlindsUPCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}