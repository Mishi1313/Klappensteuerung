#include <Arduino.h>
void setup() {

    Serial.begin(9600);       // BLE aktivieren
    delay(500);               // Warten auf Initialisierung des BLE-Moduls
    Serial.write(0x00);
    Serial.flush();           // Sicherstellen, dass alles raus ist
}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();

        if (c == 'O') {
            Serial.println("Signal O für Klappe öffnen Empfangen");
        } else if (c == 'C') {
            Serial.println("Signal C für Klappe Schliessen Empfangen");
        }
    }
}