#ifndef AHRS_BLACK_BOX_WAICRESPONSE_H
#define AHRS_BLACK_BOX_WAICRESPONSE_H

#include "Frame.h"

namespace communication
{
    class ResponseVisitor;

    enum ResponseType : uint8_t
    {
        DATA = 5,
        ACK = 10,
        BLINDS_STATUS_RSP = 15,
        MOTOR_STATUS = 20,
        ERROR = 25,
        AUTHENTICATE = 30
    };

    class Response : public Frame
    {
    public:
        Response(uint8_t dataSizeIn, ResponseType commandTypeIn);
        virtual ~Response();

        virtual std::vector<uint8_t > getFrameBytes() = 0;
        virtual std::string getName() = 0;
        virtual void accept(ResponseVisitor& visitor) = 0;

        const ResponseType& getResponseType() const;

    protected:
        virtual void initializeDataSize() = 0;

        ResponseType responseType_;

    };
}

#endif
