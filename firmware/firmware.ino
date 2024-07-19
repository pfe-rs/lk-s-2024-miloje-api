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
StepperMotor stepperMotor1(11, 50);
StepperMotor stepperMotor2(12, 47);

// Array of Capability pointers
Capability* capabilities[] = {
  &servoMotor1,
  &servoMotor2,
  &battery
};

Communication comm(SERIAL_BLUETOOTH, capabilities, sizeof(capabilities) / sizeof(Capability*));

void setup() {
  comm.commSetup(9600);
}

void loop() {
  comm.commLoop();
  delay(100);
}
