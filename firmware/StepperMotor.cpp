#include "StepperMotor.h"

/**
* Constructs a StepperMotor object.
* 
* @param stepPin The pin number for the step signal.
* @param dirPin The pin number for the direction signal.
*/
StepperMotor::StepperMotor(
    int stepPin, int dirPin
) : stepper(AccelStepper::DRIVER, stepPin, dirPin) {}

/**
* Decodes incoming instructions to control the stepper motor.
* 
* @param strs Array of strings containing the command parameters: direction, speed, and distance.
* @param serial Reference to the HardwareSerial object for serial communication.
*/
void StepperMotor::decode(String* strs, HardwareSerial& serial) {
    String dir = strs[0];
    int speed = strs[1].toInt();
    int distance = strs[2].toInt();
    moveClockwise(speed, distance);
}

/**
* Moves the stepper motor clockwise.
* 
* @param speed The speed at which to move the motor.
* @param distance The distance to move the motor in steps.
*/
void StepperMotor::moveClockwise(int speed, int distance) {
    stepper.setMaxSpeed(speed);
    stepper.setAcceleration(800);
    stepper.move(distance);
    stepper.run();
}

/**
* Runs the stepper motor if there is distance to go.
*/
void StepperMotor::run() {
    if (stepper.distanceToGo() != 0) {
        stepper.run();
    }
}

/** 
* This method returns a character "M" representing the type of the stepper motor.
* 
* @return A character representing the stepper motor's type ('M').
*/
char StepperMotor::type() {
    return 'M';
}
