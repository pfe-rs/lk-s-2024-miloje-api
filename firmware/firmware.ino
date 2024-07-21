#include "Communication.h"
#include "ServoMotor.h"
#include "StepperMotor.h"
#include "Battery.h"

// Serials
HardwareSerial& SERIAL_UART = Serial;
HardwareSerial& SERIAL_BLUETOOTH = Serial3;

ServoMotor servoMotor1(2);
ServoMotor servoMotor2(4);
Battery battery;
StepperMotor stepperMotor1(10, 52);
StepperMotor stepperMotor2(11, 47);

// Array of Capability pointers
Capability* capabilities[] = {
  &servoMotor1,
  &servoMotor2,
  &battery,
  &stepperMotor1,
  &stepperMotor2
};

Communication comm(SERIAL_BLUETOOTH, capabilities, sizeof(capabilities) / sizeof(Capability*));

void setup() {
  pinMode(6, OUTPUT);
  comm.commSetup(9600);
}

void loop() {
  comm.commLoop();
  delay(10);
}
