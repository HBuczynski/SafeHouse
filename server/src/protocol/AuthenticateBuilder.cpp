#include "AuthenticateBuilder.h"
#include "AuthenticateResponse.h"

using namespace std;
using namespace communication;

AuthenticateBuilder::AuthenticateBuilder()
{}

AuthenticateBuilder::~AuthenticateBuilder()
{}

std::unique_ptr<Response> AuthenticateBuilder::create(const std::vector<uint8_t> &dataInBytes)
{
    auto command = make_unique<AuthenticateResponse>();

    return move(command);
}
