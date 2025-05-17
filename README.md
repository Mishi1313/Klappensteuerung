# Klappensteuerung
Anhand einer selbst programmierten simplen App über MIT App Inventor, soll eine Klappensteuerung am Auto möglich sein.
In der App sind folgende Menutasten verfügbar:
Bluetoothliste Anzeigen, Verbinden, Verbindung trennen, Klappe Öffnen, Klappe schliessen

Anhand dieser Menutasten kann eine Verbinund mit dem Arduino Bluno, welcher über BLE lauft, hergestellt werden.
Beim drücken des Bluetoothsymbols erscheint ein Dropdown mit allen erreichbaren Bluetooth geräten.
Nun wird der Bluno angedrückt in der Liste und danach auf Connect um die Verbindung zum Bluno herzustellen.
Dies kann einen Moment dauern.

Mit dem Button Disconnect kann die Verbindung gekappt werden, jedoch aus Sicherheitsgründen wurde ein Alert hinzugefügt, welches das ausversehne Disconnecten verhindern soll.
Visuell ersichtlich erscheint ein Popup Fenster mit folgendem Inhalt:
ALERT
Do you really want to disconnect?

Mit Ja kann die Verbindung erfolgreich getrennt werden und mit Nein wird der Vorgang abgebrochen.

Bei erfolgreichem Verbinden leuchtet auf dem Bluno das LED "LINK" auf. Somit ist Visuell auf dem Arduino eine Verbindung ersichtlich.
Ebenfalls ersichtlich auf der App ist der Verbindungsstatus, es gibt 4 verschiedene States:
Connecting - Hier versucht er eine Verbindung herzustellen
Connected - Hier ist er mit einem BLE-Gerät verbunden.
Disconnecting - Hier kappt er die momentane Verbindung.
Disconnected - Hier zeigt er an das momentan keine Verbindung besteht.

Ist die Verbindung nun gesetzt kann anhand der zwei Buttons "Exhaust Open" & "Exhauste Close" die Klappe gesteuert werden.
Beim drücken von "Exhaust Open" versendet die App den Buchstaben "O" als String an den Arduino.
Beim drücken von "Exhaust Close" versendet die App den Buchstaben "C" ebenfalls als String an den Arduino.

Visuell erkennbar ob die Strings empgfangen wurden ist es am Arduino selbst, die LED "RX" blinkt beim Empfangen kurz auf.
Ebenfalls ersichtlich ob ein Signal erkannt wurde ist wenn im Clion der Serialmonitor aktiv ist und folgende Befehle zurück versendet wurden:
"O" = "Klappe geoeffnet (PIN HIGH)"
"C" = "Klappe geschlossen (PIN LOW)"

Wird "O" empfangen, setzt sich der PIN 8 auf "HIGH" und schaltet somit das Relais ein.
Wird "C" empfangen, setzt sicher der PIN 8 auf LOW und schaltet somit das Relaus aus.

Ist das Relais aktiv, wird auf der anderen Seite ein 12V Kontakt geschlossen und ein Magnetventil wird somit aktiv, welches für die Weiterleitung des Unterdrucks zur Unterduckdrossel zuständig ist.
Aktiv wird die Klappe geöffnet, ist diese jedoch nicht aktiv schliesst sie sich wieder.

NOTFALL BUTTONS:

Ist eine Verbindung durch welch au immer kommenden äussereneinflüssen nicht möglich, sind zwei Buttons an einer Platine noch installiert.
Ein Button schliesst die Klappe, der andere öffnet diese wieder.

Button Open auf PIN 7 setzt den PIN 9 auf "HIGH".
Button Close auf PIN 6 setzt den PIN 9 auf "LOW".
So kann von Hand die Klappe notfalls geöffnet und geschlossen werden.
