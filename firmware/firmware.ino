#include "Communication.h"
#include "ServoMotor.h"
#include "StepperMotor.h"
#include "Battery.h"
#include "UltraSonic.h"
#include "Buzzer.h"

// Hardware serials
HardwareSerial& SERIAL_UART = Serial;
HardwareSerial& SERIAL_BLUETOOTH = Serial3;

// Declaration of Milojes capabilities
ServoMotor servoMotor1(5);
ServoMotor servoMotor2(4);
Battery battery(A2);
StepperMotor stepperMotor1(2, 40);
StepperMotor stepperMotor2(3, 41);
UltraSonic ultraSonic(23,A0);
Buzzer buzzer(6);

// Array of Capability pointers
Capability* capabilities[] = {
  &servoMotor1,
  &servoMotor2,
  &battery,
  &stepperMotor1,
  &stepperMotor2,
  &ultraSonic,
  &buzzer
};

int numCapabilities = sizeof(capabilities) / sizeof(Capability*);
Communication comm(SERIAL_BLUETOOTH, capabilities, numCapabilities);

void setup() {
  comm.commSetup(9600);
}

void loop() {
  comm.commLoop();

    float batteryLevel = battery.getLevel();
  if (batteryLevel <= 11 && batteryLevel > 6) {
    buzzer.buzz(880);
    //for (int id = 0; id < numCapabilities; id++)
    //  capabilities[id]->disable();
  }
}
