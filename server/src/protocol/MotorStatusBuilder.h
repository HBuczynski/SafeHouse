#ifndef SAFEHOUSE_MOTORSTATUSBUILDER_H
#define SAFEHOUSE_MOTORSTATUSBUILDER_H

#include "ResponseBuilder.h"

namespace communication
{
    class MotorStatusBuilder final : public ResponseBuilder
    {
    public:
        MotorStatusBuilder();
        ~MotorStatusBuilder();

        virtual std::unique_ptr <Response> create(const std::vector <uint8_t> &dataInBytes) override;
    };
}
#endif
