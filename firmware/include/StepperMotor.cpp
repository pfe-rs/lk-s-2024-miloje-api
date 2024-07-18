#include "StepperMotor.h"

StepperMotor::StepperMotor(
    int stepPin,
    int dirPin
) : stepper(AccelStepper::DRIVER, stepPin, dirPin),
    stepPin(stepPin),
    dirPin(dirPin) {}

void StepperMotor::forward(float speed, float distance) {
    speed /= 5;
    distance *= (-200);

    stepper.setMaxSpeed(speed);
    stepper.setAcceleration(800);
    stepper.moveTo(distance);

    while (stepper.distanceToGo() != 0)
        stepper.run();
    stepper.stop();
}

void StepperMotor::backward(float speed, float distance) {
    speed /= 5;
    distance *= (-200);

    stepper.setMaxSpeed(speed);
    stepper.setAcceleration(800);
    stepper.moveTo(-distance);

    while (stepper.distanceToGo() != 0)
        stepper.run();
    stepper.stop();
}
