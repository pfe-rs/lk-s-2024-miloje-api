#include "Steppers.h"

Steppers::Steppers(
    int stepPinLeft,
    int dirPinLeft,
    int stepPinRight,
    int dirPinRight) : leftStepper(AccelStepper::DRIVER, stepPinLeft, dirPinLeft),
                       rightStepper(AccelStepper::DRIVER, stepPinRight, dirPinRight) {}

void Steppers::Curve(float angle, int sped, int d)
{
  angle = angle * 3.14 / 180;
  sped = sped * 6;           // brzina mm/s
  int L = 225;               // razmak medju tockovima
  float T = d / (float)sped; // d je u mm ti se snadji s
  float omega = angle / T;
  float r = omega / ((float)sped); // radijus velikog kruga

  float V_right = -(omega + 2 * sped) / 2;
  float V_left = -(V_right - omega * r);

  float N_left = V_left / 6;
  float N_right = V_right / 6;

  leftStepper.setMaxSpeed(V_right);
  leftStepper.setAcceleration(200);
  leftStepper.move(N_right);

  rightStepper.setMaxSpeed(V_left);
  rightStepper.setAcceleration(200);
  rightStepper.move(N_left);

  while ((leftStepper.distanceToGo() != 0) && (rightStepper.distanceToGo() != 0))
  {
    leftStepper.run();
    rightStepper.run();
  }

  leftStepper.stop();
  rightStepper.stop();
}

void Steppers::Spin(int angle)
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

void Steppers::Forward(int obrt, int sped)
{
  sped = sped / 5;
  obrt = -200 * obrt;
  leftStepper.setMaxSpeed(sped);
  leftStepper.setAcceleration(800);
  leftStepper.moveTo(obrt);

  rightStepper.setMaxSpeed(sped);
  rightStepper.setAcceleration(800);
  rightStepper.moveTo(-obrt);

  while ((leftStepper.distanceToGo() != 0) && (rightStepper.distanceToGo() != 0))
  {
    leftStepper.run();
    rightStepper.run();
  }
  leftStepper.stop();
  rightStepper.stop();
}

void Steppers::Forward_angle(int angle, int sped)
{
  int obrt = -200 * (((float)angle) / 360);

  leftStepper.setMaxSpeed(sped);
  leftStepper.setAcceleration(800);
  leftStepper.moveTo(obrt);

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
