#ifndef _MILOJE_H
#define _MILOJE_H
#include <AccelStepper.h>

class Steppers
{
public:
  Steppers(int stepPinLeft, int dirPinLeft, int stepPinRight, int dirPinRight);
  void Forward(int obrt, int sped);
  void Forward_angle(int angle, int sped);
  void Spin(int angle);
  void Curve(float angle, int sped, int d);

private:
  AccelStepper leftStepper;
  AccelStepper rightStepper;
};

#endif
