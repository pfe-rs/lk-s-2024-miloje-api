#ifndef _COMMUNICATION_H
#define _COMMUNICATION_H
#include "Capability.h"

class Communication
{
  public:
    Communication(HardwareSerial& serial, Capability* capabilities[]);
    void commSetup(int baudRate);           // Start listening on the serial
    void commLoop();                        // Loop for checking incoming instructions
    void decode(String *strs);          // Decoder of the incoming instruction
    void handleServo(String *strs);     // Servo instruction decoder
    void handleStepper(String *strs);   // Stepper instruction decoder
    void getCapabilities();             // Return list of capabilities (in a string)
  private:
    HardwareSerial& serial;
    Capability** capabilities;
    int numCapabilities; // Number of capabilites
};

#endif
