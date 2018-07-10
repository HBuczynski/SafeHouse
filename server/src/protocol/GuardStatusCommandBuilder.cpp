#include "GuardStatusCommandBuilder.h"
#include "GuardStatusCommand.h"

using namespace std;
using namespace communication;

GuardStatusCommandBuilder::GuardStatusCommandBuilder()
{}

GuardStatusCommandBuilder::~GuardStatusCommandBuilder()
{}

unique_ptr<Command> GuardStatusCommandBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<GuardStatusCommand>();

    return move(command);
}
