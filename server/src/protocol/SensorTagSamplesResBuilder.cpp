#include "SensorTagSamplesResBuilder.h"
#include "SensorTagSamplesResponse.h"
#include <utility/BytesConverter.h>


using namespace std;
using namespace utility;
using namespace communication;

SensorTagSamplesResBuilder::SensorTagSamplesResBuilder()
{}

SensorTagSamplesResBuilder::~SensorTagSamplesResBuilder()
{}

unique_ptr<Response> SensorTagSamplesResBuilder::create(const vector<uint8_t> &dataInBytes)
{
    vector<uint16_t > data;
    uint16_t position = INIT_DATA_POSITION;

    for(int i=0; i<9;  ++i)
    {
        data.push_back(BytesConverter::fromVectorOfUINT8toUINT16(dataInBytes, position));
        position += sizeof(uint16_t);
    }

    auto command = make_unique<SensorTagSamplesResponse>(data);

    return move(command);
}