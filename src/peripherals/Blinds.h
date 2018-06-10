
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

    enum DIRECTION
    {
        STOPPED = 0,
        UP,
        DOWN
    };

    bool init(uint16_t motorPinEnable_, uint16_t motorPWMLeft_, uint16_t motorPWMRight_, uint16_t motorPWMEnable_, uint16_t topSwitchPin_, uint16_t bottomSwitchPin_);

    void setPWMValue(unsigned int pwmValue_);
    unsigned int  getPWMValue() const;


    void moveBlindsUp();
    void moveBlindsDown();
    void blindsStop();

    static void blindsUpCallback(int gpio, int level, uint32_t tick, void *userdata);
    static void blindsDownCallback(int gpio, int level, uint32_t tick, void *userdata);

    uint8_t blindsId;
    unsigned int pwmValue;
    DIRECTION direction = DIRECTION::STOPPED;

    std::unique_ptr<Motor> motor = nullptr;
    std::unique_ptr<Switch> topSwitch = nullptr;
    std::unique_ptr<Switch> bottomSwitch = nullptr;
    std::unique_ptr<AbstractState> actualState;
    utility::Logger& logger;
};


#endif //SAFEHOUSE_BLINDS_H
