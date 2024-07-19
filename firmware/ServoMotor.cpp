#include "ServoMotor.h"

ServoMotor::ServoMotor(int pin) : pin(pin) {}

void ServoMotor::setup() {
    servo.attach(pin); 
}

void ServoMotor::decode(String* strs, HardwareSerial& serial) {
    serial.println(strs[0].toInt());
    setPosition(strs[0].toInt());
}

void ServoMotor::setPosition(int pos) {
    servo.write(pos);
}

char ServoMotor::type() {
    return 'S';
}
