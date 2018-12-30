#include "SensorTagSamplesBuilder.h"
#include "SensorTagSamplesCommand.h"

using namespace std;
using namespace communication;

SensorTagSamplesBuilder::SensorTagSamplesBuilder()
{}

SensorTagSamplesBuilder::~SensorTagSamplesBuilder()
{}

unique_ptr<Command> SensorTagSamplesBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<SensorTagSamplesCommand>();

    return move(command);
}