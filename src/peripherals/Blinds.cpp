//
// Created by marcin on 11.03.18.
//

#include "Blinds.h"


Blinds::Blinds()
{
    motor = make_unique<Motor>();
    topSwitch = make_unique<Switch>();
    bottomSwitch = make_unique<Switch>();


}

