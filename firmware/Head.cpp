#include "Head.h"
#include <Arduino.h>

Head::Head(
    int servoPinUp,
    int servoPinDown,
    int ultraPinTrig,
    int ultraPinEcho) : servoPinUp(servoPinUp),
                        servoPinDown(servoPinDown),
                        ultraPinTrig(ultraPinTrig),
                        ultraPinEcho(ultraPinEcho) {}

void Head::Setup()
{
  servoUp.attach(servoPinUp);
  servoDown.attach(servoPinDown);
}

void Head::Cross()
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    servoDown.write(i * 90);
    for (j = 0; j < 3; j++)
    {
      servoUp.write(j * 40 + 100);
      delay(2000);
    }
  }
}

void Head::SetMe(int pos_down, int pos_up)
{
  servoDown.write(pos_down);
  servoUp.write(pos_up);
}

float Head::UltraSonic()
{
  pinMode(ultraPinTrig, OUTPUT);
  pinMode(ultraPinEcho, INPUT);
  digitalWrite(ultraPinTrig, LOW);
  delayMicroseconds(5);
  digitalWrite(ultraPinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraPinTrig, LOW);
  long t = pulseIn(ultraPinEcho, HIGH);
  float s = t / 58.31;
  return s;
}
