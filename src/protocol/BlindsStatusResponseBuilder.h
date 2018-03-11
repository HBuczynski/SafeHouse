#ifndef SAFEHOUSE_BLINDSSTATUSRESPONSEBUILDER_H
#define SAFEHOUSE_BLINDSSTATUSRESPONSEBUILDER_H

#include "ResponseBuilder.h"

namespace communication
{
    class BlindsStatusResponseBuilder final : public ResponseBuilder
    {
    public:
        BlindsStatusResponseBuilder();
        ~BlindsStatusResponseBuilder();

        virtual std::unique_ptr<Response> create(const std::vector<uint8_t> &dataInBytes) override;
    };
}
#endif
