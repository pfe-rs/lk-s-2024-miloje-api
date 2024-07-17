#ifndef _HEAD_H
#define _HEAD_H
#include <Servo.h>

class ServoMotor
{
public:
  ServoMotor(int servoPinUp);
  void Setup();
  void SetMe(int pos);

private:
  int servoPin;
  Servo servo;
};

#endif