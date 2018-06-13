#ifndef SAFEHOUSE_ABSTRACTSTATE_H
#define SAFEHOUSE_ABSTRACTSTATE_H

#include "Blinds.h"
#include "PeriphManager.h"

class AbstractState {
public:
    AbstractState():stateName("AbstractState") 
	{
		periphManager= peripherials::PeriphManager::getInstance();
	};
    virtual ~AbstractState() {};

    virtual void blindsUp(Blinds & blinds) = 0;
    virtual void blindsDown(Blinds & blinds) = 0;

    virtual void blindsUpSwitch(Blinds & blinds) = 0;
    virtual void blindsDownSwitch(Blinds & blinds) = 0;

    std::string stateName;

protected:
    void setState(Blinds & blinds, AbstractState* state);
	
	peripherials::PeriphManager &periphManager_;
};


#endif //SAFEHOUSE_ABSTRACTSTATE_H
