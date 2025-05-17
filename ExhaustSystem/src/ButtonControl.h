#pragma once
#include "Arduino.h"

class ButtonControl {
public:
    ButtonControl(uint8_t pin);
    void begin();
    bool isPressed();

private:
    uint8_t _pin;
};
