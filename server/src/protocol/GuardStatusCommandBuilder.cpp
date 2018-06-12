#include "GuardStatusBuilder.h"
#include "GuardStatusCommand.h"

using namespace std;
using namespace communication;

GuardStatusBuilder::GuardStatusBuilder()
{}

GuardStatusBuilder::~GuardStatusBuilder()
{}

unique_ptr<Command> GuardStatusBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<GuardStatusCommand>();

    return move(command);
}
