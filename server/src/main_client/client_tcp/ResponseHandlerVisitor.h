#ifndef RESPONSEHANDLERVISITOR_H
#define RESPONSEHANDLERVISITOR_H

#include <protocol/ResponseVisitor.h>
#include <logger/Logger.h>

namespace communication
{
    class ResponseHandlerVisitor final : public ResponseVisitor
    {
    public:
        ResponseHandlerVisitor();
        ~ResponseHandlerVisitor();

        virtual void visit(AckResponse& data) override;
        virtual void visit(DataResponse& data) override;
        virtual void visit(ErrorResponse& data) override;
        virtual void visit(MotorStatusResponse& data) override;
        virtual void visit(BlindsStatusResponse& data) override;
        virtual void visit(AuthenticateResponse& data) override;

    private:
        utility::Logger& logger_;
    };
}

#endif