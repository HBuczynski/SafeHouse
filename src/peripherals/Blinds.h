
#ifndef SAFEHOUSE_BLINDS_H
#define SAFEHOUSE_BLINDS_H

#include <memory>

#include "Motor.h"
#include "Switch.h"
#include "AbstractState.h"


//Class defining finite state machine for window blinds usage:

class AbstractState;

class Blinds
{
public:
    Blinds(uint8_t blindsId_);
   ~Blinds();

    bool init(uint16_t motorPin_, uint16_t topSwitchPin_, uint16_t bottomSwitchPin_);

    void setPWMValue(unsigned int pwmValue_);
    unsigned int  getPWMValue() const;


    void moveBlindsUp();
    void moveBlindsDown();
    void blindsStop();

    static void blindsUpCallback(int gpio, int level, uint32_t tick, void *userdata);
    static void blindsDownCallback(int gpio, int level, uint32_t tick, void *userdata);

    uint8_t blindsId;
    unsigned int pwmValue;

    std::unique_ptr<Motor> motor = nullptr;
    std::unique_ptr<Switch> topSwitch = nullptr;
    std::unique_ptr<Switch> bottomSwitch = nullptr;
    std::unique_ptr<AbstractState> actualState;
    utility::Logger& logger;
};


#endif //SAFEHOUSE_BLINDS_H
