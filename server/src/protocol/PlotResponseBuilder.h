#ifndef SAFEHOUSE_PLOTRESPONSEBUILDER_H
#define SAFEHOUSE_PLOTRESPONSEBUILDER_H

#include "ResponseBuilder.h"

namespace communication
{
    class PlotResponseBuilder final : public ResponseBuilder
    {
    public:
        PlotResponseBuilder();
        ~PlotResponseBuilder();

        virtual std::unique_ptr<Response> create(const std::vector<uint8_t> &dataInBytes) override;

    };
}

#endif