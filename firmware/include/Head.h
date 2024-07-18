#ifndef _HEAD_H
#define _HEAD_H
#include <Servo.h>

class Head
{
public:
  Head(int servoPinUp, int servoPinDown, int ultraPinTrig, int ultraPinEcho);
  void Setup();
  void Cross();
  void SetMe(int pos_down, int pos_up);
  float UltraSonic();

private:
  int servoPinUp;
  int servoPinDown;
  int ultraPinTrig;
  int ultraPinEcho;
  Servo servoUp;
  Servo servoDown;
};

#endif
