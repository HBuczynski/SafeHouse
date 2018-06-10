#include "AutomaticBlindsBuilder.h"
#include "AutomaticBlindsCommand.h"

using namespace std;
using namespace communication;

AutomaticBlindsBuilder::AutomaticBlindsBuilder()
{}

AutomaticBlindsBuilder::~AutomaticBlindsBuilder()
{}

std::unique_ptr<Command> AutomaticBlindsBuilder::create(const std::vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<AutomaticBlindsCommand>();

    return move(command);
}
