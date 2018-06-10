#include "UserInHomeBuilder.h"
#include "UserInHomeCommand.h"

using namespace std;
using namespace communication;

UserInHomeBuilder::UserInHomeBuilder()
{}

UserInHomeBuilder::~UserInHomeBuilder()
{}

std::unique_ptr<Command> UserInHomeBuilder::create(const std::vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<UserInHomeCommand>();

    return move(command);
}
