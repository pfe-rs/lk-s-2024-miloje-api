#include "StepperMotor.h"

StepperMotor::StepperMotor(
    int stepPin, int dirPin
) : stepper(AccelStepper::DRIVER, stepPin, dirPin) {}

void StepperMotor::decode(String* strs) {
    String dir = strs[1];
    int spd = strs[2].toInt();
    int distance = strs[3].toInt();
    if(dir == "F")
      forward(spd, distance);
    else if(dir == "B")
      backward(spd, distance);
}

void StepperMotor::forward(int speed, int distance) {
    speed /= 5;
    distance *= (-200);

    stepper.setMaxSpeed(speed);
    stepper.setAcceleration(800);
    stepper.moveTo(distance);

    while (stepper.distanceToGo() != 0)
        stepper.run();
    stepper.stop();
}

void StepperMotor::backward(int speed, int distance) {
    speed /= 5;
    distance *= (-200);

    stepper.setMaxSpeed(speed);
    stepper.setAcceleration(800);
    stepper.moveTo(-distance);

    while (stepper.distanceToGo() != 0)
        stepper.run();
    stepper.stop();
}

char StepperMotor::type() {
    return 'M';
}