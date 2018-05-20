
#include "Switch.h"

#include <iostream>

bool Switch::registerHandler(gpioISRFuncEx_t fun, const int &edge, const int &timeout,void *intData)
{
    interruptHandler = fun;

    interruptData = intData;

    if(!gpioSetISRFuncEx(pinNumber, edge, timeout,interruptHandler, intData))
    {
        std::cout << "ISR register correct." << std::endl;
        return true;
    }
    return false;
}