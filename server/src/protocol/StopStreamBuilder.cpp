#include "StopStreamBuilder.h"
#include "StopStreamCommand.h"

using namespace std;
using namespace communication;

StopStreamBuilder::StopStreamBuilder()
{}

StopStreamBuilder::~StopStreamBuilder()
{}

unique_ptr<Command> StopStreamBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<StopStreamCommand>();

    return move(command);
}