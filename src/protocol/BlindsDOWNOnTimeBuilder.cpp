#include "BlindsDOWNOnTimeBuilder.h"
#include "BlindsDOWNOnTimeCommand.h"

#include <utility/BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;

BlindsDOWNOnTimeBuilder::BlindsDOWNOnTimeBuilder()
{}

BlindsDOWNOnTimeBuilder::~BlindsDOWNOnTimeBuilder()
{}

std::unique_ptr<Command> BlindsDOWNOnTimeBuilder::create(const std::vector<uint8_t> &commandInBytes)
{
    uint32_t epochTime;

    epochTime = BytesConverter::fromVectorOfUINT8toUINT32(commandInBytes, INIT_EPOCH_TIME_POSITION_IN_FRAME);

    auto command = make_unique<BlindsDOWNOnTimeCommand>(epochTime);

    return move(command);
}


