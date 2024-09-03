#include "Buzzer.h"

Buzzer::Buzzer(int pin) : pin(pin) {}

void Buzzer::setup() {
    pinMode(pin, OUTPUT);
}

void Buzzer::decode(String* strs, HardwareSerial& serial) {
    run();
}

void Buzzer::run() {
    tone(pin, 880);
    delay(100);
    tone(pin, 440);
    delay(100);
    noTone(pin);
    delay(20);
}

char Buzzer::type() {
    return 'Z';
}
