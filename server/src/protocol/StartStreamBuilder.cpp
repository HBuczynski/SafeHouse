#include "StartStreamBuilder.h"
#include "StartStreamCommand.h"

using namespace std;
using namespace communication;

StartStreamBuilder::StartStreamBuilder()
{}

StartStreamBuilder::~StartStreamBuilder()
{}

unique_ptr<Command> StartStreamBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<StartStreamCommand>();

    return move(command);
}