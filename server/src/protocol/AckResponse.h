#ifndef AHRS_ACKRESPONSE_H
#define AHRS_ACKRESPONSE_H

#include "Response.h"

namespace communication
{
    enum AckType : uint8_t
    {
        OK = 10,
        FAIL = 20,
        CONNECTION_ENDED = 30,
        CHANGED_MODE = 40,
	    THIEF = 50
    };

    class AckResponse final : public Response
    {
    public:
        AckResponse(AckType type);
        ~AckResponse();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor& visitor) override;

        AckType getAckType() const;
        void setAckType(AckType type);

    private:
        virtual void initializeDataSize() override;

        AckType type_;
    };
}

#endif //AHRS_ACKRESPONSE_H
