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
                        steppers(stepLeftPin, stepLeftDir, stepRightPin, stepRightDir),
                        head(servoPinUp, servoPinDown, ultraPinTrig, ultraPinEcho) {}

void Communication::Setup()
{
  serial.begin(9600);
  head.Setup();
}

void Communication::DecodeServo(String *strs)
{
  if (strs[2] == "10")
  {
    head.Cross();
  }
  else if (strs[2] == "11")
  {
    int par1 = strs[3].toInt();
    int par2 = strs[4].toInt();
    head.SetMe(par1, par2);
  }
}

void Communication::DecodeStepper(String *strs)
{
  int par1 = strs[3].toInt();
  int par2 = strs[4].toInt();
  if (strs[2] == "10")
  {
    steppers.Forward(par1, par2);
  }
  else if (strs[2] == "11")
  {
    steppers.Forward_angle(par1, par2);
  }
  else if (strs[2] == "12")
  {
    steppers.Spin(par1);
  }
  else if (strs[2] == "13")
  {
    float param1 = strs[3].toFloat();
    int par3 = strs[5].toInt();
    steppers.Curve(param1, par2, par3);
  }
}

void Communication::DecodeMotor(String *strs)
{
  if (strs[1] == "S")
  {
    DecodeServo(strs);
  }
  else if (strs[1] == "A")
  {
    DecodeStepper(strs);
  }
}

void Communication::DecodeType(String *strs)
{
  if (strs[0] == "M")
  {
    DecodeMotor(strs);
  }
  else if (strs[0] == "S")
  {
    serial.println(head.UltraSonic());
  }
}

void Communication::Loop()
{
  String str;
  String strs[20];
  if (serial.available() > 0)
  {
    str = serial.readString();
  }
  int StringCount = 0;
  while (str.length() > 0)
  {
    int index = str.indexOf(' ');
    if (index == -1)
    {
      strs[StringCount++] = str;
      break;
    }
    else
    {
      strs[StringCount++] = str.substring(0, index);
      str = str.substring(index + 1);
    }
  }
  DecodeType(strs);
}
