#include "Battery.h"

const float ADCResolution = 1024.0;
const float arduinoVoltage  = 5.0;
const float measurementOffset = 0.7;

Battery::Battery(int pin) : pin(pin) {}

void Battery::decode(String* strs, HardwareSerial& serial) {
    serial.println(getLevel());
}

float Battery::getLevel() {
    return (float(analogRead(pin)) / ADCResolution) * 3 * arduinoVoltage + measurementOffset;
}

char Battery::type() {
    return 'B';
}
