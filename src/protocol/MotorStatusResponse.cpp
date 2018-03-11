#include "MotorStatusResponse.h"

#include "ResponseVisitor.h"

using namespace std;
using namespace communication;

MotorStatusResponse::MotorStatusResponse(MotorStatus type)
        : Response(10, ResponseType::MOTOR_STATUS),
          type_(type)
{}

MotorStatusResponse::~MotorStatusResponse()
{}

vector<uint8_t> MotorStatusResponse::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(responseType_));
    frame.push_back(static_cast<uint8_t>(type_));

    return frame;
}

string MotorStatusResponse::getName()
{
    return string("MotorStatusResponse");
}

void MotorStatusResponse::accept(ResponseVisitor &visitor)
{
    visitor.visit(*this);
}

MotorStatus MotorStatusResponse::getMotorStatus() const
{
    return type_;
}

void MotorStatusResponse::setMotorStatus(MotorStatus type)
{
    type = type_;
}

void MotorStatusResponse::initializeDataSize()
{
    uint16_t dataSize = sizeof(responseType_);
    dataSize += sizeof(type_);

    setDataSize(dataSize);
}
