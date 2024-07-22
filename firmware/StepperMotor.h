#ifndef _STEPPERMOTOR_H
#define _STEPPERMOTOR_H
#include "Capability.h"

class StepperMotor : public Capability {
    public:
        StepperMotor(int stepPin, int dirPin);
        void decode(String* strs, HardwareSerial& serial) override;
        void forward(int speed, int distance);
        void backward(int speed, int distance);
        void run();
        char type() override;
    private:
        int stepPin, dirPin;
        AccelStepper stepper;
};

#endif
