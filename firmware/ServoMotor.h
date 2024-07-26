#ifndef _SERVOMOTOR_H
#define _SERVOMOTOR_H
#include "Capability.h"
#include <Servo.h>

class ServoMotor : public Capability {
    public:
        ServoMotor(int pin);
        void decode(String* strs, HardwareSerial& serial) override;
        void setup() override;
        void setPosition(int pos);
        char type() override; 
    private:
        int pin;
        Servo servo;
};

#endif