#include "SwitchesInterface.h"

using namespace std;
using namespace hardware;

SwitchesInterface::SwitchesInterface(uint8_t pinNumber)
    : pinNumber_(pinNumber),
      state_(SwitcheState::DISABLED)
{

}

SwitchesInterface::~SwitchesInterface()
{
}

SwitcheState SwitchesInterface::getState()
{
    return state_;
}
