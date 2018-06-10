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
    direction = UP;
}

Blinds::~Blinds()
{

}

bool Blinds::init(uint16_t motorPinEnable_, uint16_t motorPWMLeft_, uint16_t motorPWMRight_, uint16_t motorPWMEnable_, uint16_t topSwitchPin_, uint16_t bottomSwitchPin_)
{
    if(logger.isInformationEnable())
    {
        const std::string message = std::string("Initializing");
        logger.writeLog(utility::LogType::INFORMATION_LOG, message);
    }
    motor->setMode(motorPinEnable_,PI_OUTPUT,PI_PUD_OFF);
    motor->setMotorPins(motorPWMLeft_, motorPWMRight_, motorPWMEnable_);
    motor->setRange(1000);
    setPWMValue(1000);
    topSwitch->setMode(topSwitchPin_, PI_INPUT, PI_PUD_UP);
    bottomSwitch->setMode(bottomSwitchPin_, PI_INPUT, PI_PUD_UP);

    motor->init();
    topSwitch->init();
    bottomSwitch->init();
    int top = -1, bottom = -1;
    top = topSwitch->pinRead();
    bottom = bottomSwitch->pinRead();

    if(logger.isInformationEnable())
    {
        const std::string message = std::string("State up: " + std::to_string(top));
        logger.writeLog(utility::LogType::INFORMATION_LOG, message);
    }
    if(logger.isInformationEnable())
    {
        const std::string message = std::string("State down: " + std::to_string(bottom));
        logger.writeLog(utility::LogType::INFORMATION_LOG, message);
    }
    if(((!topSwitch->pinRead()) && (!bottomSwitch->pinRead())))
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

    if(topSwitch->registerHandler(blindsUpCallback, EITHER_EDGE, 0, reinterpret_cast<void*>(this))
                         && bottomSwitch->registerHandler(blindsDownCallback, EITHER_EDGE, 0, reinterpret_cast<void*>(this)))
    {
        const std::string message = std::string("Callbacks registered.");
        logger.getInstance().writeLog(utility::LogType::INFORMATION_LOG, message);
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
    motor->setPWM(pwmValue,motor->getRightPWMPin());
    motor->setPWM(0,motor->getLeftPWMPin());
    //TODO: setting direction (two pins)
}

void Blinds::moveBlindsUp()
{
    motor->setPWM(pwmValue,motor->getLeftPWMPin());
    motor->setPWM(0,motor->getRightPWMPin());
    //TODO: setting direction (two pins)
}

void Blinds::blindsStop()
{
    motor->setPWM(0,motor->getLeftPWMPin());
    motor->setPWM(0,motor->getRightPWMPin());
}

void Blinds::blindsUpCallback(int gpio, int level, uint32_t tick, void *userdata)
{
    Blinds* blinds = reinterpret_cast<Blinds*>(userdata);
        const std::string message = std::string("Blinds up callback invoked");
        utility::Logger::getInstance().writeLog(utility::LogType::INFORMATION_LOG, message);
    blinds->actualState->blindsUpSwitch(*blinds);
}

void Blinds::blindsDownCallback(int gpio, int level, uint32_t tick, void *userdata)
{
    Blinds* blinds = reinterpret_cast<Blinds*>(userdata);
        const std::string message = std::string("Blinds down callback invoked");
        utility::Logger::getInstance().writeLog(utility::LogType::INFORMATION_LOG, message);
    blinds->actualState->blindsDownSwitch(*blinds);
}

