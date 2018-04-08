#include "Camera.h"

Camera::Camera(uint8_t deviceID_)
    : GPIO(deviceID_, GPIOType::CAMERA)
{

}

Camera::~Camera()
{}
