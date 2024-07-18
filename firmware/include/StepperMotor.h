#ifndef _STEPPERMOTOR_H
#define _STEPPERMOTOR_H
#include <AccelStepper.h>

class StepperMotor {
    public:
        StepperMotor(int stepPin, int dirPin);
        void forward(float speed, float distance);
        void backward(float speed, float distance);
    private:
        int stepPin;
        int dirPin;
        AccelStepper stepper;
};

#endif
