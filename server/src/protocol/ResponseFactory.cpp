#include "ResponseFactory.h"

#include "DataResponseBuilder.h"
#include "AckResponseBuilder.h"
#include "ErrorBuilder.h"
#include "MotorStatusBuilder.h"
#include "GuardStatusBuilder.h"
#include "BlindsStatusResponseBuilder.h"
#include "AuthenticateBuilder.h"
#include "SensorTagSamplesResBuilder.h"

using namespace std;
using namespace communication;

ResponseFactory::ResponseFactory()
{}

ResponseFactory::~ResponseFactory()
{}

unique_ptr<Response> ResponseFactory::createCommand(const vector<uint8_t> &commandInBytes)
{
    const auto type = static_cast<ResponseType >(commandInBytes[RESPONSE_DATA_TYPE_POSITION]);

    switch (type)
    {
        case ResponseType::DATA :
            builder_ = make_unique<DataResponseBuilder>();
            return move(builder_->create(commandInBytes));
        case ResponseType::ACK:
            builder_ = make_unique<AckResponseBuilder>();
            return move(builder_->create(commandInBytes));
        case ResponseType::ERROR:
            builder_ = make_unique<ErrorBuilder>();
            return move(builder_->create(commandInBytes));
        case ResponseType::MOTOR_STATUS:
            builder_ = make_unique<MotorStatusBuilder>();
            return move(builder_->create(commandInBytes));
		case ResponseType::GUARD_STATUS:
            builder_ = make_unique<GuardStatusBuilder>();
            return move(builder_->create(commandInBytes));
        case ResponseType::BLINDS_STATUS_RSP:
            builder_ = make_unique<BlindsStatusResponseBuilder>();
            return move(builder_->create(commandInBytes));
        case ResponseType::AUTHENTICATE:
            builder_ = make_unique<AuthenticateBuilder>();
            return move(builder_->create(commandInBytes));
        case ResponseType::SENSOR_TAG:
            builder_ = make_unique<SensorTagSamplesResBuilder>();
            return move(builder_->create(commandInBytes));
        default:
            throw invalid_argument("Received command does not register in factory.");
    }
}