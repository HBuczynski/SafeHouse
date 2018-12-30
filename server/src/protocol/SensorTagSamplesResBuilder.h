#ifndef SAFEHOUSE_SENSORTAGSAMPLESRESBUILDER_H
#define SAFEHOUSE_SENSORTAGSAMPLESRESBUILDER_H

#include "ResponseBuilder.h"

namespace communication
{
    class SensorTagSamplesResBuilder final : public ResponseBuilder
    {
    public:
        SensorTagSamplesResBuilder();
        ~SensorTagSamplesResBuilder();

        virtual std::unique_ptr<Response> create(const std::vector<uint8_t> &dataInBytes) override;

    };
}


#endif