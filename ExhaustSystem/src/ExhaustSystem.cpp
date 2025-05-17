#include "ExhaustSystem.h"
#include "Arduino.h"

ExhaustSystem::ExhaustSystem(uint8_t outputPinSmartphone)
    : _outputPinSmartphone(outputPinSmartphone) {}

void ExhaustSystem::begin() {
    pinMode(_outputPinSmartphone, OUTPUT);
    digitalWrite(_outputPinSmartphone, LOW);
    Serial.println("Klappe initial geschlossen.");
}

void ExhaustSystem::handleBluetooth() {
    while (Serial.available()) {
        char c = Serial.read();
        _processCommand(c);
    }
}

void ExhaustSystem::_processCommand(char command) {
    if (command == 'O') {
        setOutput(true);
    } else if (command == 'C') {
        setOutput(false);
    }
}

void ExhaustSystem::setOutput(bool state) {
    digitalWrite(_outputPinSmartphone, state ? HIGH : LOW);
    Serial.println(state ? "Klappe geoeffnet (Pin HIGH)" : "Klappe geschlossen (Pin LOW)");
}
