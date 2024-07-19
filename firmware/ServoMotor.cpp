#include "ServoMotor.h"

ServoMotor::ServoMotor(int pin) {
    servo.attach(pin);
    servo.write(0); // default position
}

void ServoMotor::decode(String* strs) {
    setPosition(strs[0].toInt());
}

void ServoMotor::setPosition(int pos) {
    servo.write(pos);
}

char ServoMotor::type() {
    return 'S';
}