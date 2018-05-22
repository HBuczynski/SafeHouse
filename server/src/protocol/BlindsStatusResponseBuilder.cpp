#include "BlindsStatusResponse.h"
#include "BlindsStatusResponseBuilder.h"

using namespace std;
using namespace communication;

BlindsStatusResponseBuilder::BlindsStatusResponseBuilder()
{}

BlindsStatusResponseBuilder::~BlindsStatusResponseBuilder()
{}

unique_ptr<Response> BlindsStatusResponseBuilder::create(const vector<uint8_t> &dataInBytes)
{
    const auto status = static_cast<BlindsStatus>(dataInBytes[INIT_DATA_POSITION]);
    const auto mode = static_cast<BlindsMode >(dataInBytes[INIT_DATA_POSITION+1]);

    auto command = make_unique<BlindsStatusResponse>(status, mode);

    return move(command);
}
