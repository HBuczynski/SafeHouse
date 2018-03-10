#include "BlindsUPOnTimeBuilder.h"
#include "BlindsUPOnTimeCommand.h"

#include <BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;

BlindsUPOnTimeBuilder::BlindsUPOnTimeBuilder()
{}

BlindsUPOnTimeBuilder::~BlindsUPOnTimeBuilder()
{}

unique_ptr<Command> BlindsUPOnTimeBuilder::create(const vector<uint8_t> &commandInBytes)
{
    uint16_t epochTime;

    epochTime = BytesConverter::fromVectorOfUINT8toUINT16(commandInBytes, INIT_EPOCH_TIME_POSITION_IN_FRAME);

    auto command = make_unique<BlindsUPOnTimeCommand>(epochTime);

    return move(command);
}
