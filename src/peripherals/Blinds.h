//
// Created by marcin on 11.03.18.
//

#ifndef SAFEHOUSE_BLINDS_H
#define SAFEHOUSE_BLINDS_H

#include <memory>

#include <Motor.h>
#include <Switch.h>

using namespace std;

class Blinds {
public:
    Blinds() = default;
    ~Blinds() = default;



private:
    unique_ptr<Motor> motor = nullptr;
    unique_ptr<Switch> topSwitch = nullptr;
    unique_ptr<Switch> bottomSwitch = nullptr;
};


#endif //SAFEHOUSE_BLINDS_H
