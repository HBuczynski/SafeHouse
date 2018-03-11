#include "UserOutOfHomeCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

UserOutOfHomeCommand::UserOutOfHomeCommand()
        : Command(10, CommandType::USER_OUT_OF_HOME)
{}

UserOutOfHomeCommand::~UserOutOfHomeCommand()
{}

vector<uint8_t> UserOutOfHomeCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

string UserOutOfHomeCommand::getName()
{
    return string("UserOutOfHomeCommand");
}

void UserOutOfHomeCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void UserOutOfHomeCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}
