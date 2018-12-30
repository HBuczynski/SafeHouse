#include "PlotResponse.h"
#include "ResponseVisitor.h"
#include "CommandVisitor.h"

#include <utility/BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;

PlotResponse::PlotResponse(const std::vector<uint16_t> &data, const std::vector<uint16_t> &timestamp,
                           ParameterType parameterType)
        : Response(10, ResponseType::PLOT_RESPONSE),
          data_(data),
          timestamp_(timestamp),
          parameterType_(parameterType)
{}

PlotResponse::~PlotResponse()
{}

std::vector<uint8_t> PlotResponse::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(responseType_));
    frame.push_back(static_cast<uint8_t>(parameterType_));

    for(auto sample : data_) {
        BytesConverter::appendUINT16toVectorOfUINT8(sample, frame);
    }

    for(auto time : timestamp_) {
        BytesConverter::appendUINT16toVectorOfUINT8(time, frame);
    }

    return frame;
}

std::string PlotResponse::getName()
{
    return string("PlotCommand");
}

void PlotResponse::accept(ResponseVisitor &visitor)
{
    visitor.visit(*this);
}

void PlotResponse::initializeDataSize()
{
    uint16_t dataSize = sizeof(responseType_);
    dataSize += sizeof(parameterType_);
    dataSize += sizeof(uint16_t)*data_.size();
    dataSize += sizeof(uint16_t)*timestamp_.size();

    setDataSize(dataSize);
}

const std::vector<uint16_t> PlotResponse::getData() const
{
    return data_;
}

void PlotResponse::setData(const std::vector<uint16_t> &data)
{
    data_ = data;
}
const vector<uint16_t> &PlotResponse::getTimestamp() const
{
    return timestamp_;
}

void PlotResponse::setTimestamp(const vector<uint16_t> &timestamp)
{
    timestamp_ = timestamp;
}

ParameterType PlotResponse::getParameterType() const
{
    return parameterType_;
}

void PlotResponse::setParameterType(ParameterType parameterType)
{
    parameterType_ = parameterType;
}

