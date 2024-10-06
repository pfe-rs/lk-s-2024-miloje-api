#ifndef _COMMUNICATION_H
#define _COMMUNICATION_H
#include "Capability.h"

/**
* Communication is a call for managing serial communication.
*/

class Communication
{
    public:
        Communication(HardwareSerial& serial, Capability* capabilities[], int numCapabilities);
        void commSetup(int baudRate);       
        void commLoop();                   
        void decode(String *strs);          
        void getCapabilities();            
    private:
        HardwareSerial& serial;
        Capability** capabilities;
        int numCapabilities;  
};

#endif
