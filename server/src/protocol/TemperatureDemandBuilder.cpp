#include "TemperatureDemandBuilder.h"
#include "TemperatureDemandCommand.h"

using namespace std;
using namespace communication;

TemperatureDemandBuilder::TemperatureDemandBuilder()
{}

TemperatureDemandBuilder::~TemperatureDemandBuilder()
{}

unique_ptr<Command> TemperatureDemandBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<TemperatureDemandCommand>();

    return move(command);
}
