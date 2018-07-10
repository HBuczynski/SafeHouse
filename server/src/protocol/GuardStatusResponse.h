#ifndef SAFEHOUSE_GUARDSTATUSRESPONSE_H
#define SAFEHOUSE_GUARDSTATUSRESPONSE_H

#include "Response.h"

namespace communication
{
    enum GuardStatus : uint8_t
    {
        ON = 10,
        OFF = 20,
    };

    class GuardStatusResponse final : public Response
    {
    public:
        GuardStatusResponse(GuardStatus type);
        ~GuardStatusResponse();

        virtual std::vector <uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor &visitor) override;

        GuardStatus getGuardStatus() const;
        void setGuardStatus(GuardStatus type);

    private:
        virtual void initializeDataSize() override;

        GuardStatus type_;
    };
}
#endif
