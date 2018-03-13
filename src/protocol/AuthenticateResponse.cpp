#include "AuthenticateResponse.h"
#include "ResponseVisitor.h"

using namespace std;
using namespace communication;

AuthenticateResponse::AuthenticateResponse()
        : Response(10, ResponseType::AUTHENTICATE)
{}

AuthenticateResponse::~AuthenticateResponse()
{}

vector<uint8_t> AuthenticateResponse::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(responseType_));

    return frame;
}

string AuthenticateResponse::getName()
{
    return string("AuthenticateResponse");
}

void AuthenticateResponse::accept(ResponseVisitor &visitor)
{
    visitor.visit(*this);
}

void AuthenticateResponse::initializeDataSize()
{
    uint16_t dataSize = sizeof(responseType_);

    setDataSize(dataSize);
}
