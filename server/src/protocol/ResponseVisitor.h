#ifndef AHRS_RESPONSEVISITOR_H
#define AHRS_RESPONSEVISITOR_H

#include "AckResponse.h"
#include "DataResponse.h"
#include "ErrorResponse.h"
#include "MotorStatusResponse.h"
#include "GuardStatusResponse.h"
#include "BlindsStatusResponse.h"
#include "AuthenticateResponse.h"

namespace communication
{
    class ResponseVisitor
    {
    public:
        ResponseVisitor() {};
        virtual ~ResponseVisitor() {};

        virtual void visit(AckResponse& data) = 0;
        virtual void visit(DataResponse& data) = 0;
        virtual void visit(ErrorResponse& data) = 0;
        virtual void visit(MotorStatusResponse& data) = 0;
        virtual void visit(BlindsStatusResponse& data) = 0;
        virtual void visit(AuthenticateResponse& data) = 0;
		virtual void visit(GuardStatusResponse& data) = 0;
    };
}

#endif //AHRS_RESPONSEVISITOR_H
