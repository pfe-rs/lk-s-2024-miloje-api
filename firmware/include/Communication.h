#ifndef _COMMUNICATION_H
#define _COMMUNICATION_H

#include "Wheels.h"
#include "Head.h"

class Communication
{
public:
  Communication(HardwareSerial& serial, int servoPinUp, int servoPinDown, int ultraPinTrig, int ultraPinEcho, int stepLeftPin, int stepLeftDir, int stepRightPin, int stepRightDir);
  void setup();
  void loop();
  void decode(String *strs);
  void decodeMotor(String *strs);
  void decodeWheels(String *strs);
  void decodeHead(String *strs);
  void decodeSensor(String *strs);
  void decodeServo(String *strs);
  void decodeStepper(String *strs);

private:
  HardwareSerial& serial;
  Wheels wheels;
  Head head;
};

#endif
