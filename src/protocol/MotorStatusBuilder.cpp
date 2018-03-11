#include "MotorStatusBuilder.h"
#include "MotorStatusResponse.h"

using namespace std;
using namespace communication;

MotorStatusBuilder::MotorStatusBuilder()
{}

MotorStatusBuilder::~MotorStatusBuilder()
{}

std::unique_ptr<Response> MotorStatusBuilder::create(const std::vector<uint8_t> &dataInBytes)
{
    const auto motorStatus = static_cast<MotorStatus>(dataInBytes[INIT_DATA_POSITION]);

    auto command = make_unique<MotorStatusResponse>(motorStatus);
    return move(command);
}
