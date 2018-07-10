#ifndef SWITCHES_DRIVER_H
#define SWITCHES_DRIVER_H

namespace hardware
{
    enum SwitcheState : uint8_t
    {
        ENABLED = 0x10,
        DISABLED = 0x20
    };

    class SwitchesInterface
    {
    public:
        SwitchesInterface(uint8_t pinNumber);
        ~SwitchesInterface();

        SwitcheState getState();

    private:
        uint8_t pinNumber_;
        SwitcheState state_;
    };
}

#endif