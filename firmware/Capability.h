#ifndef _CAPABILITY_H
#define _CAPABILITY_H
#include <Servo.h>
#include <AccelStepper.h>

class Capability {
    public:
        Capability();
        virtual char type();
        virtual void setup();
        virtual void decode(String* strs, HardwareSerial& serial);
        virtual void run();
        virtual float checkLevel(); // temporary here
        bool enabled=true;
        void enable();
        void disable();
};

#endif
