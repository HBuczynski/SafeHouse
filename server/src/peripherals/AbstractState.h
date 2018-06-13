#ifndef SAFEHOUSE_ABSTRACTSTATE_H
#define SAFEHOUSE_ABSTRACTSTATE_H

#include "Blinds.h"

namespace peripherials
{	
	class PeriphManager;
}

class AbstractState {
public:
    AbstractState();
    virtual ~AbstractState() {};

    virtual void blindsUp(Blinds & blinds) = 0;
    virtual void blindsDown(Blinds & blinds) = 0;

    virtual void blindsUpSwitch(Blinds & blinds) = 0;
    virtual void blindsDownSwitch(Blinds & blinds) = 0;

    std::string stateName;

protected:
    void setState(Blinds & blinds, AbstractState* state);
	
	peripherials::PeriphManager &periphManager;
};


#endif //SAFEHOUSE_ABSTRACTSTATE_H
