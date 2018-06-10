#ifndef SAFEHOUSE_ERRORBUILDER_H
#define SAFEHOUSE_ERRORBUILDER_H

#include "ResponseBuilder.h"

namespace communication
{
    class ErrorBuilder final : public ResponseBuilder
    {
    public:
        ErrorBuilder();
        ~ErrorBuilder();

        virtual std::unique_ptr<Response> create(const std::vector<uint8_t> &dataInBytes) override;

    };
}
#endif
