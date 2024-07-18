#include "Communication.h"

Communication::Communication(
    HardwareSerial& serial,
    int servoPinUp,
    int servoPinDown,
    int ultraPinTrig,
    int ultraPinEcho,
    int stepLeftPin,
    int stepLeftDir,
    int stepRightPin,
    int stepRightDir) : serial(serial),
                        wheels(stepLeftPin, stepLeftDir, stepRightPin, stepRightDir),
                        head(servoPinUp, servoPinDown, ultraPinTrig, ultraPinEcho) {}

void Communication::setup() {
  serial.begin(9600);
  head.Setup();
}

void Communication::decode(String *strs) {
  if (strs[0] == "M")
    decodeMotor(strs);
  else if (strs[0] == "W")
    decodeWheels(strs);
  else if (strs[0] == "H")
    decodeHead(strs);
  else if (strs[0] == "S")
    decodeSensor(strs);
}

void Communication::decodeMotor(String *strs) {
   if(strs[1] == "1")
    decodeServo(strs);
  else if (strs[1] == "2")
    decodeStepper(strs);
}

void Communication::decodeWheels(String *strs) {
  String p1 = strs[2];
  String p2 = strs[3];

  if(strs[1].toInt() == 0)
    wheels.Forward(p1.toInt(), p2.toInt());
  else if(strs[1].toInt() == 1)
    wheels.Backward(p1.toInt(), p2.toInt());
  else if(strs[1].toInt() == 2)
    wheels.Spin(p1.toInt());
}

void Communication::decodeHead(String *strs) {
  String p1 = strs[2];
  String p2 = strs[3];

  if(strs[1] == "2")
    head.SetMe(p1.toInt(), p2.toInt());
}

void Communication::decodeSensor(String *strs) {
  if(strs[2] == "0")
    serial.println(head.UltraSonic());
}

void Communication::decodeServo(String *strs) {
  // ID
}

void Communication::decodeStepper(String *strs) {
  // ID
}

void Communication::loop() {
  if (serial.available() > 0) {
    String str, strs[20];
    str = serial.readString();
    int StringCount = 0;
    while (str.length() > 0) {
      int index = str.indexOf(' ');
      if (index == -1) {
        strs[StringCount++] = str;
        break;
      } else {
        strs[StringCount++] = str.substring(0, index);
        str = str.substring(index + 1);
      }
    }

    decode(strs);
  }
}
