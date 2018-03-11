#ifndef SAFEHOUSE_MOTORSTATUSRESPONSE_H
#define SAFEHOUSE_MOTORSTATUSRESPONSE_H

#include "Response.h"

namespace communication
{
    enum MotorStatus : uint8_t
    {
        START = 10,
        STOP = 20,
    };

    class MotorStatusResponse final : public Response
    {
    public:
        MotorStatusResponse(MotorStatus type);
        ~MotorStatusResponse();

        virtual std::vector <uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor &visitor) override;

        MotorStatus getMotorStatus() const;
        void setMotorStatus(MotorStatus type);

    private:
        virtual void initializeDataSize() override;

        MotorStatus type_;
    };
}
#endif
