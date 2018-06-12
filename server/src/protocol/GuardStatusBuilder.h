#ifndef SAFEHOUSE_GUARDSTATUSBUILDER_H
#define SAFEHOUSE_GUARDSTATUSBUILDER_H

#include "ResponseBuilder.h"

namespace communication
{
    class GuardStatusBuilder final : public ResponseBuilder
    {
    public:
        GuardStatusBuilder();
        ~GuardStatusBuilder();

        virtual std::unique_ptr <Response> create(const std::vector <uint8_t> &dataInBytes) override;
    };
}
#endif
