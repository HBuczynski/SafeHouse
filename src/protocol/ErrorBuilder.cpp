#include "ErrorBuilder.h"
#include "ErrorResponse.h"

using namespace std;
using namespace communication;

ErrorBuilder::ErrorBuilder()
{}

ErrorBuilder::~ErrorBuilder()
{}

unique_ptr<Response> ErrorBuilder::create(const vector<uint8_t> &dataInBytes)
{
    const auto ackType = static_cast<ErrorType>(dataInBytes[INIT_DATA_POSITION]);

    auto command = make_unique<ErrorResponse>(ackType);

    return move(command);
}
