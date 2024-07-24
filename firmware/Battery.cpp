#include "Battery.h"

Battery::Battery() {}

void Battery::decode(String* strs, HardwareSerial& serial) {
    serial.println(checkLevel());
}

float Battery::checkLevel() {
    int readingPin = A2;
    float batteryLevel = float(analogRead(A2)) / 1023.0 * 15.0+0.7;
    return batteryLevel;
}

char Battery::type() {
    return 'B';
}
