#include <Arduino.h>

String bleBuffer = "";
bool lastConnectedState = false;

void setup() {
    Serial.begin(9600);
    Serial.println("System gestartet...");
}

void loop() {
    while (Serial.available()) {
        char c = Serial.read();
        bleBuffer += c;


        // Prüfen auf Connected
        if (bleBuffer.endsWith("V") && !lastConnectedState) {
            Serial.println("Connected");
            lastConnectedState = true;
            bleBuffer = "";  // Buffer leeren
        }

        // Prüfen auf Disconnected
        if (bleBuffer.endsWith("N") && lastConnectedState) {
            Serial.println("Disconnected");
            lastConnectedState = false;
            bleBuffer = "";  // Buffer leeren
        }
        if (bleBuffer.endsWith("O")) {
            Serial.println("Offen");
            bleBuffer = "";  // Buffer leeren
        }

        if (bleBuffer.endsWith("C")) {
            Serial.println("Geschlossen");
            bleBuffer = "";  // Buffer leeren
        }
    }
}
