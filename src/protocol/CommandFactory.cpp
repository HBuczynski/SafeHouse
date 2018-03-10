#include "CommandFactory.h"
#include "BlindsDOWNOnTimeBuilder.h"
#include "BlindsUPBuilder.h"
#include "BlindsStatusBuilder.h"
#include "BlindsDOWNBuilder.h"
#include "BlindsUPOnTimeBuilder.h"
#include "AutomaticBlindsBuilder.h"

#include <stdexcept>

using namespace std;
using namespace communication;

CommandFactory::CommandFactory()
{}

CommandFactory::~CommandFactory()
{}

unique_ptr<Command> CommandFactory::createCommand(const vector<uint8_t> &commandInBytes)
{
    const auto type = static_cast<CommandType>(commandInBytes[COMMAND_TYPE_POSITION]);

    switch (type)
    {
        case CommandType::BLINDS_UP :
            builder_ = make_unique<BlindsUPBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::BLINDS_DOWN :
            builder_ = make_unique<BlindsDOWNBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::BLINDS_UP_ON_TIME :
            builder_ = make_unique<BlindsUPOnTimeBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::BLINDS_DOWN_ON_TIME :
            builder_ = make_unique<BlindsDOWNOnTimeBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::BLINDS_STATUS :
            builder_ = make_unique<BlindsStatusBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::AUTOMATIC_BLINDS :
            builder_ = make_unique<AutomaticBlindsBuilder>();
            return move(builder_->create(commandInBytes));
        default:
            throw invalid_argument("Received command does not register in factory.");

    }
}
