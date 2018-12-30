#include "CommandFactory.h"
#include "BlindsDOWNOnTimeBuilder.h"
#include "BlindsUPBuilder.h"
#include "BlindsStatusBuilder.h"
#include "BlindsDOWNBuilder.h"
#include "BlindsUPOnTimeBuilder.h"
#include "AutomaticBlindsBuilder.h"
#include "TemperatureDemandBuilder.h"
#include "UserOutOfHomeBuilder.h"
#include "UserInHomeBuilder.h"
#include "EndConnectionBuilder.h"
#include "SnapshotBuilder.h"
#include "StartStreamBuilder.h"
#include "StopStreamBuilder.h"
#include "GuardStatusCommandBuilder.h"
#include "MotorStatusCommandBuilder.h"
#include "SensorTagSamplesBuilder.h"

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
        case CommandType::TEMPERATURE_DEMAND :
            builder_ = make_unique<TemperatureDemandBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::USER_OUT_OF_HOME :
            builder_ = make_unique<UserOutOfHomeBuilder>();
            return move(builder_->create(commandInBytes));
		case CommandType::USER_IN_HOME :
            builder_ = make_unique<UserInHomeBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::SNAPSHOT :
            builder_ = make_unique<SnapshotBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::START_STREAM :
            builder_ = make_unique<StartStreamBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::STOP_STREAM :
            builder_ = make_unique<StopStreamBuilder>();
            return move(builder_->create(commandInBytes));
		case CommandType::MOTOR_STATUS_COMMAND :
            builder_ = make_unique<MotorStatusCommandBuilder>();
            return move(builder_->create(commandInBytes));
		case CommandType::GUARD_STATUS_COMMAND :
            builder_ = make_unique<GuardStatusCommandBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::END_CONNECTION :
            builder_ = make_unique<EndConnectionBuilder>();
            return move(builder_->create(commandInBytes));
        case CommandType::SENSOR_TAG_SAMPLES :
            builder_ = make_unique<SensorTagSamplesBuilder>();
            return move(builder_->create(commandInBytes));
        default:
            throw invalid_argument("Received command does not register in factory.");

    }
}
