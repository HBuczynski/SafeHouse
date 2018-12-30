#include "SensorTagSamplesResponse.h"

#include "ResponseVisitor.h"
#include <utility/BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;

SensorTagSamplesResponse::SensorTagSamplesResponse(const vector<uint16_t > &data)
        : Response(10, ResponseType::SENSOR_TAG),
          data_(data)
{}

SensorTagSamplesResponse::~SensorTagSamplesResponse()
{}

vector<uint8_t> SensorTagSamplesResponse::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(responseType_));

    for(auto value : data_) {
        BytesConverter::appendUINT16toVectorOfUINT8(value, frame);
    }

    return frame;
}

string SensorTagSamplesResponse::getName()
{
    return string("SensorTagSamplesResponse");
}

void SensorTagSamplesResponse::accept(ResponseVisitor &visitor)
{
    visitor.visit(*this);
}

vector<uint16_t > SensorTagSamplesResponse::getData() const
{
    return data_;
}

void SensorTagSamplesResponse::setMotorStatus(const vector<uint16_t > &data)
{
    data_ = data;
}

void SensorTagSamplesResponse::initializeDataSize()
{
    uint16_t dataSize = sizeof(responseType_);
    dataSize += sizeof(uint16_t)*data_.size();

    setDataSize(dataSize);
}
