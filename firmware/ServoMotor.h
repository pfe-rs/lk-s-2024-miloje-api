#ifndef _SERVOMOTOR_H
#define _SERVOMOTOR_H
#include "Capability.h"

class ServoMotor : public Capability {
    public:
        ServoMotor(int pin);
        void decode(String* strs) override;
        void setPosition(int pos);
        char type() override; 
    private:
        Servo servo;
};

#endif