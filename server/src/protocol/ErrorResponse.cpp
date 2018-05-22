#include "ErrorResponse.h"
#include "ResponseVisitor.h"

using namespace std;
using namespace communication;

ErrorResponse::ErrorResponse(ErrorType type)
        : Response(10, ResponseType::ERROR),
          type_(type)
{}

ErrorResponse::~ErrorResponse()
{}

vector<uint8_t> ErrorResponse::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(responseType_));
    frame.push_back(static_cast<uint8_t>(type_));

    return frame;
}

string ErrorResponse::getName()
{
    return string("ErrorResponse");
}

void ErrorResponse::accept(ResponseVisitor &visitor)
{
    visitor.visit(*this);
}

ErrorType ErrorResponse::getErrorType() const
{
    return type_;
}

void ErrorResponse::setErrorType(ErrorType type)
{
    type_ = type;
}

void ErrorResponse::initializeDataSize()
{
    uint16_t dataSize = sizeof(responseType_);
    dataSize += sizeof(type_);

    setDataSize(dataSize);
}
