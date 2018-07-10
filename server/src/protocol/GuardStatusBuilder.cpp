#include "GuardStatusBuilder.h"
#include "GuardStatusResponse.h"

using namespace std;
using namespace communication;

GuardStatusBuilder::GuardStatusBuilder()
{}

GuardStatusBuilder::~GuardStatusBuilder()
{}

std::unique_ptr<Response> GuardStatusBuilder::create(const std::vector<uint8_t> &dataInBytes)
{
    const auto motorStatus = static_cast<GuardStatus>(dataInBytes[INIT_DATA_POSITION]);

    auto command = make_unique<GuardStatusResponse>(motorStatus);
    return move(command);
}
