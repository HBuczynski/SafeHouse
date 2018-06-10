#include "UserInHomeCommand.h"
#include "CommandVisitor.h"

using namespace std;
using namespace communication;

UserInHomeCommand::UserInHomeCommand()
        : Command(10, CommandType::USER_IN_HOME)
{}

UserInHomeCommand::~UserInHomeCommand()
{}

vector<uint8_t> UserInHomeCommand::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(commandType_));

    return frame;
}

string UserInHomeCommand::getName()
{
    return string("UserinHomeCommand");
}

void UserInHomeCommand::accept(CommandVisitor &visitor)
{
    visitor.visit(*this);
}

void UserInHomeCommand::initializeDataSize()
{
    uint16_t dataSize = sizeof(commandType_);

    setDataSize(dataSize);
}
