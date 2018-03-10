#ifndef AHRS_BLACK_BOX_FRAMEVISITOR_H
#define AHRS_BLACK_BOX_FRAMEVISITOR_H

#include "BlindsDOWNOnTimeCommand.h"
#include "BlindsUPOnTimeCommand.h"
#include "BlindsUPCommand.h"
#include "BlindsDOWNCommand.h"
#include "BlindsStatusCommand.h"
#include "AutomaticBlindsCommand.h"

namespace communication
{
    class CommandVisitor
    {
    public:
        CommandVisitor(){};
        virtual ~CommandVisitor(){};

        virtual void visit(BlindsDOWNOnTimeCommand& command) = 0;
        virtual void visit(BlindsUPOnTimeCommand& command) = 0;
        virtual void visit(BlindsUPCommand& command) = 0;
        virtual void visit(BlindsDOWNCommand& command) = 0;
        virtual void visit(BlindsStatusCommand& command) = 0;
        virtual void visit(AutomaticBlindsCommand& command) = 0;
    };
}
#endif
