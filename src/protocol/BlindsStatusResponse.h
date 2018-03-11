#ifndef SAFEHOUSE_BLINDSSTATUSRESPONSE_H
#define SAFEHOUSE_BLINDSSTATUSRESPONSE_H

#include "Response.h"

namespace communication
{
    enum BlindsStatus : uint8_t
    {
        UP = 10,
        DOWN = 20
    };

    enum BlindsMode : uint8_t
    {
        MANUAL = 10,
        AUTOMATIC = 20,
        SET_ON_TIME_UP = 30,
        SET_ON_TIME_DOWN = 40,
        SET_ON_TIME_UP_AND_DOWN = 50

    };

    class BlindsStatusResponse final : public Response
    {
    public:
        BlindsStatusResponse(BlindsStatus status, BlindsMode mode);
        ~BlindsStatusResponse();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor& visitor) override;

        BlindsStatus getBlindsStatus() const;
        void setBlindsStatus(BlindsStatus status);

        BlindsMode getBlindsMode() const;
        void setBlindsMode(BlindsMode mode);

    private:
        virtual void initializeDataSize() override;

        BlindsStatus status_;
        BlindsMode mode_;
    };
}

#endif
