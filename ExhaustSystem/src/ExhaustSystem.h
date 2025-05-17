#pragma once
#include "Arduino.h"

class ExhaustSystem {
public:
    ExhaustSystem(uint8_t outputPinSmartphone);
    void begin();
    void handleBluetooth();
    void setOutput(bool state);

private:
    uint8_t _outputPinSmartphone;
    void _processCommand(char command);
};
