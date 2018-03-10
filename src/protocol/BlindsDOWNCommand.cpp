#include "BlindsDOWNCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;


BlindsDOWNCommand::BlindsDOWNCommand()
    : Command(10, CommandType::BLINDS_DOWN)
{}

BlindsDOWNCommand::~BlindsDOWNCommand()
{}

vector<uint8_t> BlindsDOWNCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

string BlindsDOWNCommand::getName()
{
    return string("BlindsDOWNCommand");
}

void BlindsDOWNCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void BlindsDOWNCommand::initializeDataSize()
{
    setDataSize(sizeof(commandType_));
}
