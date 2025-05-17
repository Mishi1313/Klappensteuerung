#include "ExhaustSystem.h"
#include "ButtonControl.h"
#include "Arduino.h"

//PIN belegungen für die Steuerung der Klappe
#define OUTPUT_PIN 8
#define BUTTON_OPEN_PIN 7
#define BUTTON_CLOSE_PIN 6

//Definition der Buttons
ExhaustSystem exhaustsystem(OUTPUT_PIN);
ButtonControl buttonOpen(BUTTON_OPEN_PIN);
ButtonControl buttonClose(BUTTON_CLOSE_PIN);

void setup() {
    Serial.begin(9600);
    delay(200);

    Serial.println("Klappensteuerung bereit, warte auf Befehle");

    exhaustsystem.begin();
    buttonOpen.begin();
    buttonClose.begin();
}

void loop() {
    // Klasse Aufrufen für verarbeitung von Befehlen per App
    exhaustsystem.handleBluetooth();

    // Manuelle Klappensteuerung über Buttons

    //Klappe öffnen
    if (buttonOpen.isPressed()) {
        exhaustsystem.setOutput(true);
    }

    // Klappe schliessen
    if (buttonClose.isPressed()) {
        exhaustsystem.setOutput(false);
    }
}
