#include "UserOutOfHomeBuilder.h"
#include "UserOutOfHomeCommand.h"

using namespace std;
using namespace communication;

UserOutOfHomeBuilder::UserOutOfHomeBuilder()
{}

UserOutOfHomeBuilder::~UserOutOfHomeBuilder()
{}

std::unique_ptr<Command> UserOutOfHomeBuilder::create(const std::vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<UserOutOfHomeCommand>();

    return move(command);
}
