#ifndef _STEPPERMOTOR_H
#define _STEPPERMOTOR_H
#include "Capability.h"
#include <AccelStepper.h>

/**
* StepperMotor is a class for the stepper motors, which is one of the capabilities.
*/

class StepperMotor : public Capability {
    public:
        StepperMotor(int stepPin, int dirPin);
        void decode(String* strs, HardwareSerial& serial) override;
        void moveClockwise(int speed, int distance);
        void run() override;
        char type() override;
    private:
        int stepPin, dirPin;
        AccelStepper stepper;
};

#endif
