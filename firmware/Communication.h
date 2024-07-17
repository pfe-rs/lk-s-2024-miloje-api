#ifndef _COMMUNICATION_H
#define _COMMUNICATION_H

#include "Steppers.h"
#include "Head.h"

class Communication
{
public:
  Communication(HardwareSerial& serial, int servoPinUp, int servoPinDown, int ultraPinTrig, int ultraPinEcho, int stepLeftPin, int stepLeftDir, int stepRightPin, int stepRightDir);
  void Setup();
  void Loop();
  void DecodeType(String *strs);
  void DecodeMotor(String *strs);
  void DecodeSensor(String *strs);
  void DecodeServo(String *strs);
  void DecodeStepper(String *strs);

private:
  HardwareSerial& serial;
  Steppers steppers;
  Head head;
};

#endif
