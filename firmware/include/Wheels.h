#ifndef _WHEELS_H
#define _WHEELS_H
#include <AccelStepper.h>

class Wheels
{
public:
  Wheels(int stepPinLeft, int dirPinLeft, int stepPinRight, int dirPinRight);
  void Forward(int obrt, int sped);
  void Backward(int obrt, int sped);
  void Spin(int angle);

private:
  AccelStepper leftStepper;
  AccelStepper rightStepper;
};

#endif
