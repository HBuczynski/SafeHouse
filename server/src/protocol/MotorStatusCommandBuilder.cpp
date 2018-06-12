#include "MotorStatusBuilder.h"
#include "MotorStatusCommand.h"

using namespace std;
using namespace communication;

MotorStatusBuilder::MotorStatusBuilder()
{}

MotorStatusBuilder::~MotorStatusBuilder()
{}

unique_ptr<Command> MotorStatusBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<MotorStatusCommand>();

    return move(command);
}
