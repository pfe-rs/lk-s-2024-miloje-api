#include "Battery.h"

Battery::Battery(int pin) : pin(pin) {}

void Battery::decode(String* strs, HardwareSerial& serial) {
    serial.println(getLevel());
}

float Battery::getLeve() {
    int ADC_RESOLUTION=1024;
    int ARDUINO_VOLTAGE=5;
    float MEASUREMENT_OFFSET=0.7;
    return (float(analogRead(pin)) / (float)ADC_RESOLUTION) * 3 * (float)ARDUINO_VOLTAGE + MEASUREMENT_OFFSET;
}

char Battery::type() {
    return 'B';
}
