#ifndef SAFEHOUSE_PLOTRESPONSE_H
#define SAFEHOUSE_PLOTRESPONSE_H

#include "PlotCommand.h"
#include "Response.h"

namespace communication
{
    class PlotResponse final : public Response
    {
    public:
        PlotResponse(const std::vector<uint16_t > &data, const std::vector<uint16_t > &timestamp, ParameterType parameterType);
        ~PlotResponse();

        virtual std::vector <uint8_t> getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor &visitor) override;

        const std::vector<uint16_t > getData() const;
        void setData(const std::vector<uint16_t > &data);


        const std::vector<uint16_t> &getTimestamp() const;
        void setTimestamp(const std::vector<uint16_t> &timestamp_);

        ParameterType getParameterType() const;
        void setParameterType(ParameterType parameterType_);

    private:
        virtual void initializeDataSize() override;

        std::vector<uint16_t > data_;
        std::vector<uint16_t > timestamp_;
        ParameterType parameterType_;
    };
}

#endif