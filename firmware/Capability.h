#ifndef _CAPABILITY_H
#define _CAPABILITY_H
#define ARDUINO 100
#include <Servo.h>
#include <AccelStepper.h>

class Capability {
    public:
        Capability();
        virtual char type();
        virtual void decode(String* strs);
};

#endif
