#include "Wheels.h"

Wheels::Wheels(
    int stepPinLeft,
    int dirPinLeft,
    int stepPinRight,
    int dirPinRight) : leftStepper(AccelStepper::DRIVER, stepPinLeft, dirPinLeft),
                       rightStepper(AccelStepper::DRIVER, stepPinRight, dirPinRight) {}


void Wheels::Spin(int angle)
{
  float obrt = 1.6 * ((float)angle);
  int spido = 500;
  leftStepper.setMaxSpeed(spido);
  leftStepper.setAcceleration(200);
  leftStepper.move(obrt);

  rightStepper.setMaxSpeed(spido);
  rightStepper.setAcceleration(200);
  rightStepper.move(obrt);
  int i;
  while ((leftStepper.distanceToGo() != 0) && (rightStepper.distanceToGo() != 0))
  {
    leftStepper.run();
    rightStepper.run();
  }
  leftStepper.stop();
  rightStepper.stop();
}

void Wheels::Forward(int obrt, int sped)
{
  sped = sped / 5;
  obrt = -200 * obrt;
  leftStepper.setMaxSpeed(sped);
  leftStepper.setAcceleration(800);
  leftStepper.move(obrt);

  rightStepper.setMaxSpeed(sped);
  rightStepper.setAcceleration(800);
  rightStepper.move(-obrt);

  while ((leftStepper.distanceToGo() != 0) && (rightStepper.distanceToGo() != 0))
  {
    leftStepper.run();
    rightStepper.run();
  }
  leftStepper.stop();
  rightStepper.stop();
}

void Wheels::Backward(int obrt, int sped)
{
  sped = sped / 5;
  obrt = -100 * obrt;
  leftStepper.setMaxSpeed(sped);
  leftStepper.setAcceleration(800);
  leftStepper.moveTo(-obrt);

  rightStepper.setMaxSpeed(sped);
  rightStepper.setAcceleration(800);
  rightStepper.moveTo(obrt);

  while ((leftStepper.distanceToGo() != 0) && (rightStepper.distanceToGo() != 0))
  {
    leftStepper.run();
    rightStepper.run();
  }
  leftStepper.stop();
  rightStepper.stop();
}
