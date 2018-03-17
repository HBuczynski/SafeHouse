#ifndef SAFEHOUSE_AUTHENTICATEBUILDER_H
#define SAFEHOUSE_AUTHENTICATEBUILDER_H

#include "ResponseBuilder.h"

namespace communication
{
    class AuthenticateBuilder final : public ResponseBuilder
    {
    public:
        AuthenticateBuilder();
        ~AuthenticateBuilder();

        virtual std::unique_ptr<Response> create(const std::vector<uint8_t> &dataInBytes) override;
    };
}


#endif
