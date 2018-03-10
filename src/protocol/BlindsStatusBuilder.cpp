#include "BlindsStatusBuilder.h"
#include "BlindsStatusCommand.h"

#include <utility/BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;

BlindsStatusBuilder::BlindsStatusBuilder()
{}

BlindsStatusBuilder::~BlindsStatusBuilder()
{}

unique_ptr<Command> BlindsStatusBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<BlindsStatusCommand>();

    return move(command);
}


