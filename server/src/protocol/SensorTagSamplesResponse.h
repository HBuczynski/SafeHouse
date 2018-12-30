#ifndef SAFEHOUSE_SENSORTAGSAMPLESRESPONSE_H
#define SAFEHOUSE_SENSORTAGSAMPLESRESPONSE_H

#include "Response.h"

namespace communication
{
    class SensorTagSamplesResponse final : public Response
    {
    public:
        SensorTagSamplesResponse(const std::vector<uint16_t > &data);
        ~SensorTagSamplesResponse();

        virtual std::vector <uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor &visitor) override;

        std::vector<uint16_t > getData() const;
        void setMotorStatus(const std::vector<uint16_t > &data);

    private:
        virtual void initializeDataSize() override;

        std::vector<uint16_t > data_;
    };
}

#endif