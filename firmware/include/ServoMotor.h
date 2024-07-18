#ifndef _SERVOMOTOR_H
#define _SERVOMOTOR_H
#include <Servo.h>
#include <Arduino.h>

class ServoMotor {
    public:
        ServoMotor(int servoPinUp);
        void setPosition(int pos);

    private:
        int servoPin;
        Servo servo;
};

#endif