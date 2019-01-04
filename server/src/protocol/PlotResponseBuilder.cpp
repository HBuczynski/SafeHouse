#include "PlotResponseBuilder.h"
#include "PlotResponse.h"

#include <utility/BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;

PlotResponseBuilder::PlotResponseBuilder()
{}

PlotResponseBuilder::~PlotResponseBuilder()
{}

unique_ptr<Response> PlotResponseBuilder::create(const vector<uint8_t> &dataInBytes)
{
    vector<uint16_t > data;
    vector<uint16_t > timestamp;
    uint16_t position = INIT_DATA_POSITION;

    const auto parameterType = static_cast<ParameterType>(dataInBytes[position]);
    position++;

    for(int i=0; i<1000; ++i) {
        data.push_back(BytesConverter::fromVectorOfUINT8toUINT16(dataInBytes, position));
        position += 2;
    }

    for(int i=0; i<1000; ++i) {
        timestamp.push_back(BytesConverter::fromVectorOfUINT8toUINT64(dataInBytes, position));
        position += 8;
    }

    auto command = make_unique<PlotResponse>(data, timestamp, parameterType);

    return move(command);
}