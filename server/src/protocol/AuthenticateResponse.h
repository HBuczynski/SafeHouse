#ifndef SAFEHOUSE_AUTHENTICATERESPONSE_H
#define SAFEHOUSE_AUTHENTICATERESPONSE_H

#include "Response.h"

namespace communication
{
    class AuthenticateResponse final : public Response
    {
    public:
        AuthenticateResponse();
        ~AuthenticateResponse();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor &visitor) override;

    private:
        virtual void initializeDataSize() override;

    };
}

#endif
