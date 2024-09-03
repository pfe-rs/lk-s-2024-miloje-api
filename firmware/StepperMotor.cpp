#include "StepperMotor.h"

StepperMotor::StepperMotor(
    int stepPin, int dirPin
) : stepper(AccelStepper::DRIVER, stepPin, dirPin) {}

void StepperMotor::decode(String* strs, HardwareSerial& serial) {
    String dir = strs[0];
    int speed = strs[1].toInt();
    int distance = strs[2].toInt();
    moveClockwise(speed, distance);
}

void StepperMotor::moveClockwise(int speed, int distance) {
    stepper.setMaxSpeed(speed);
    stepper.setAcceleration(800);
    stepper.move(distance);
    stepper.run();
}


void StepperMotor::run() {
    if (stepper.distanceToGo() != 0) {
        stepper.run();
    }
}

char StepperMotor::type() {
    return 'M';
}
