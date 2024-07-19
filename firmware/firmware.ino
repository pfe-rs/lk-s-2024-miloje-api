#define UBRRH
#define UBRR3H
#include "Communication.h"
#include "ServoMotor.h"
#include "StepperMotor.h"

// Serials
HardwareSerial& SERIAL_UART = Serial;
HardwareSerial& SERIAL_BLUETOOTH = Serial3;

ServoMotor servoMotor1(2);
ServoMotor servoMotor2(3);
StepperMotor stepperMotor1(11, 50);
StepperMotor stepperMotor2(12, 47);

// Array of Capability pointers
Capability* capabilities[] = {
  &stepperMotor1,
  &stepperMotor2,
  &servoMotor1,
  &servoMotor2 
};

Communication comm(SERIAL_UART, capabilities);

void setup() {
  comm.commSetup(9600);
}

void loop() {
  comm.commLoop();
  delay(500);
}
