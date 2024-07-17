#include "ServoMotor.h"

#include <Arduino.h>


ServoMotor::ServoMotor(int servoPin) : servoPin(servoPin){}

void Head::Setup()
{
  servoUp.attach(servoPinUp);
  servoDown.attach(servoPinDown);
}