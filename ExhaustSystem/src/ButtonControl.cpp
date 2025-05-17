#include "ButtonControl.h"
#include <Arduino.h>

ButtonControl::ButtonControl(uint8_t pin) : _pin(pin) {}

void ButtonControl::begin() {
    pinMode(_pin, INPUT_PULLUP);
}

bool ButtonControl::isPressed() {
    return digitalRead(_pin) == LOW; // aktiv LOW
}
