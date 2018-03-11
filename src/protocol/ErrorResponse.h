#ifndef SAFEHOUSE_ERRORRESPONSE_H
#define SAFEHOUSE_ERRORRESPONSE_H

#include "Response.h"

namespace communication
{
    enum ErrorType : uint8_t
    {
        ENGINE_FAILURE = 10,
        CONNECTION_TIMEOUT = 20
    };

    class ErrorResponse final : public Response
    {
    public:
        ErrorResponse(ErrorType type);

        ~ErrorResponse();

        virtual std::vector<uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor &visitor) override;

        ErrorType getErrorType() const;
        void setErrorType(ErrorType type);

    private:
        virtual void initializeDataSize() override;

        ErrorType type_;
    };
}

#endif //SAFEHOUSE_ERRORRESPONSE_H
