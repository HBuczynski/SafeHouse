#include "BlindsUPBuilder.h"
#include "BlindsUPCommand.h"

#include <utility/BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;

BlindsUPBuilder::BlindsUPBuilder()
{}

BlindsUPBuilder::~BlindsUPBuilder()
{}

unique_ptr<Command> BlindsUPBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<BlindsUPCommand>();

    return move(command);
}


