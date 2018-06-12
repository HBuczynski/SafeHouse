#include "GuardStatusResponse.h"

#include "ResponseVisitor.h"

using namespace std;
using namespace communication;

GuardStatusResponse::GuardStatusResponse(GuardStatus type)
        : Response(10, ResponseType::GUARD_STATUS),
          type_(type)
{}

GuardStatusResponse::~GuardStatusResponse()
{}

vector<uint8_t> GuardStatusResponse::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(responseType_));
    frame.push_back(static_cast<uint8_t>(type_));

    return frame;
}

string GuardStatusResponse::getName()
{
    return string("GuardStatusResponse");
}

void GuardStatusResponse::accept(ResponseVisitor &visitor)
{
    visitor.visit(*this);
}

GuardStatus GuardStatusResponse::getGuardStatus() const
{
    return type_;
}

void GuardStatusResponse::setGuardStatus(GuardStatus type)
{
    type = type_;
}

void GuardStatusResponse::initializeDataSize()
{
    uint16_t dataSize = sizeof(responseType_);
    dataSize += sizeof(type_);

    setDataSize(dataSize);
}
