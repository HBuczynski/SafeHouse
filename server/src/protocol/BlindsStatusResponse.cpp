#include "BlindsStatusResponse.h"
#include "ResponseVisitor.h"

using namespace std;
using namespace communication;

BlindsStatusResponse::BlindsStatusResponse(BlindsStatus status, BlindsMode mode)
        : Response(10, ResponseType::BLINDS_STATUS_RSP),
          status_(status),
          mode_(mode)

{}

BlindsStatusResponse::~BlindsStatusResponse()
{}

vector<uint8_t> BlindsStatusResponse::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(responseType_));
    frame.push_back(static_cast<uint8_t>(status_));
    frame.push_back(static_cast<uint8_t>(mode_));

    return frame;
}

std::string BlindsStatusResponse::getName()
{
    return string("BlindsStatusResponse");
}

void BlindsStatusResponse::accept(ResponseVisitor &visitor)
{
    visitor.visit(*this);
}

BlindsStatus BlindsStatusResponse::getBlindsStatus() const
{
    return status_;
}

void BlindsStatusResponse::setBlindsStatus(BlindsStatus status)
{
    status_ = status;
}

BlindsMode BlindsStatusResponse::getBlindsMode() const
{
    return mode_;
}

void BlindsStatusResponse::setBlindsMode(BlindsMode mode)
{
    mode_ = mode;
}

void BlindsStatusResponse::initializeDataSize()
{
    uint16_t dataSize = sizeof(responseType_);
    dataSize += sizeof(status_);
    dataSize += sizeof(mode_);

    setDataSize(dataSize);
}
