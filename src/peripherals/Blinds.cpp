#include "Blinds.h"
#include "AbstractState.h"
#include "ClosedState.h"
#include "ErrorState.h"
#include "IdleState.h"
#include "MovingState.h"
#include "OpenedState.h"


Blinds::Blinds(uint8_t blindsId_)
    : blindsId(blindsId_), logger(utility::Logger::getInstance())
{
    motor = std::make_unique<Motor>(blindsId_);
    topSwitch = std::make_unique<Switch>(blindsId_, GPIOType::UPPER_SWITCH);
    bottomSwitch = std::make_unique<Switch>(blindsId_, GPIOType::DOWN_SWITCH);
    actualState = std::make_unique<IdleState>();
}

Blinds::~Blinds()
{

}

bool Blinds::init(uint16_t motorPin_, uint16_t topSwitchPin_, uint16_t bottomSwitchPin_)
{
    if(logger.isInformationEnable())
    {
        const std::string message = std::string("Initializing");
        logger.writeLog(utility::LogType::INFORMATION_LOG, message);
    }
    motor->setMode(motorPin_, PI_OUTPUT, PI_PUD_OFF);
    topSwitch->setMode(topSwitchPin_, PI_INPUT, PI_PUD_UP);
    bottomSwitch->setMode(bottomSwitchPin_, PI_INPUT, PI_PUD_UP);

    motor->init();
    topSwitch->init();
    bottomSwitch->init();

    if(!topSwitch->pinRead() && !bottomSwitch->pinRead())
    {
        actualState.reset(new ErrorState());
    }
    else if(!topSwitch->pinRead())
    {
        actualState.reset(new OpenedState());
    }
    else if(!bottomSwitch->pinRead())
    {
        actualState.reset(new ClosedState());
    }
    else
    {
        actualState.reset(new IdleState());
    }

    if(logger.isInformationEnable())
    {
        const std::string message = std::string("Initial state: " + actualState->stateName);
        logger.writeLog(utility::LogType::INFORMATION_LOG, message);
    }

    if(motor->init() && topSwitch->registerHandler(blindsUpCallback, EITHER_EDGE, 0, static_cast<void*>(actualState.get()))
                         && bottomSwitch->registerHandler(blindsDownCallback, EITHER_EDGE, 0, static_cast<void*>(actualState.get())))
    {
        return true;
    }
    return false;
}

void Blinds::setPWMValue(unsigned int pwmValue_)
{
    pwmValue = pwmValue_;
}

unsigned int Blinds::getPWMValue() const
{
    return pwmValue;
}


void Blinds::moveBlindsDown()
{
    motor->setPWM(pwmValue);
    //TODO: setting direction (two pins)
}

void Blinds::moveBlindsUp()
{
    motor->setPWM(pwmValue);
    //TODO: setting direction (two pins)
}

void Blinds::blindsStop()
{
    motor->setPWM(0);
}

void Blinds::blindsUpCallback(int gpio, int level, uint32_t tick, void *userdata)
{
    Blinds* blinds = static_cast<Blinds*>(userdata);
    blinds->actualState->blindsUpSwitch(*blinds);
}

void Blinds::blindsDownCallback(int gpio, int level, uint32_t tick, void *userdata)
{
    Blinds* blinds = static_cast<Blinds*>(userdata);
    blinds->actualState->blindsDownSwitch(*blinds);
}

