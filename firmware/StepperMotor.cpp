#include "StepperMotor.h"

StepperMotor::StepperMotor(
    int stepPin, int dirPin
) : stepper(AccelStepper::DRIVER, stepPin, dirPin) {}

void StepperMotor::decode(String* strs, HardwareSerial& serial) {
    String dir = strs[0];
    int spd = strs[1].toInt();
    int distance = strs[2].toInt();
    serial.println(dir);
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
    stepper.move(distance);

    while (stepper.distanceToGo() != 0)
        stepper.run();
    stepper.stop();
}

void StepperMotor::backward(int speed, int distance) {
    speed /= 5;
    distance *= (-200);

    stepper.setMaxSpeed(speed);
    stepper.setAcceleration(800);
    stepper.move(-distance);

    while (stepper.distanceToGo() != 0)
        stepper.run();
    stepper.stop();
}

char StepperMotor::type() {
    return 'M';
}
