#include "BlindsDOWNBuilder.h"
#include "BlindsDOWNCommand.h"

using namespace std;
using namespace communication;

BlindsDOWNBuilder::BlindsDOWNBuilder()
{}

BlindsDOWNBuilder::~BlindsDOWNBuilder()
{}

unique_ptr<Command> BlindsDOWNBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<BlindsDOWNCommand>();

    return move(command);
}

