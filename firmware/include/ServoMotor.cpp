#include "ServoMotor.h"

ServoMotor::ServoMotor(int servoPin) : servoPin(servoPin) {
    servo.attach(servoPin);
}

void ServoMotor::setPosition(int pos) {
    servo.write(pos);
}