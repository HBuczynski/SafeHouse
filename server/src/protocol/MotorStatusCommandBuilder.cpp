#include "MotorStatusCommandBuilder.h"
#include "MotorStatusCommand.h"

using namespace std;
using namespace communication;

MotorStatusCommandBuilder::MotorStatusCommandBuilder()
{}

MotorStatusCommandBuilder::~MotorStatusCommandBuilder()
{}

unique_ptr<Command> MotorStatusCommandBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<MotorStatusCommand>();

    return move(command);
}
