
#ifndef SAFEHOUSE_BLINDS_H
#define SAFEHOUSE_BLINDS_H

#include <memory>

#include <Motor.h>
#include <Switch.h>

#include <BlindsStates.h>

//Class defining finite state machine for window blinds usage:

class AbstractState;

class Blinds: public GPIO
{
public:

    Blinds(uint8_t device_id);
    virtual ~Blinds() = default;

    bool init(uint16_t motorPin_, uint16_t topSwitchPin_, uint16_t bottomSwitchPin_) const;


    int blindsUpCallback(int gpio, int level, uint32_t tick, void *userdata);
    int blindsDownCallback(int gpio, int level, uint32_t tick, void *userdata);

private:
    std::unique_ptr<Motor> motor = nullptr;
    std::unique_ptr<Switch> topSwitch = nullptr;
    std::unique_ptr<Switch> bottomSwitch = nullptr;
    std::unique_ptr<AbstractState> actualState;
};


#endif //SAFEHOUSE_BLINDS_H
