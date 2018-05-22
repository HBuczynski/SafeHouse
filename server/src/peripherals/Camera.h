#ifndef SAFEHOUSE_CAMERA_H
#define SAFEHOUSE_CAMERA_H

#include "GPIO.h"

class Camera : public GPIO
{
public:
    Camera(uint8_t deviceID_);
    ~Camera();
};


#endif //SAFEHOUSE_CAMERA_H
