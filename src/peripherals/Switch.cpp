
#include "Switch.h"


bool Switch::registerHandler(gpioISRFuncEx_t fun, const int &edge, const int &timeout,void *intData)
{
    interruptHandler = fun;

    interruptData = intData;

    if(!gpioSetISRFuncEx(pinNumber, edge, timeout,interruptHandler, intData))
    {
        return true;
    }
    return false;
}