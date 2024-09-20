#ifndef _CAPABILITY_H
#define _CAPABILITY_H

#include <Arduino.h>
#include <HardwareSerial.h>

/**
* Capability is an abstract class for all capabilities.
*/

class Capability {
    public: 
        virtual char type() = 0;
        virtual void setup();
        virtual void decode(String* strs, HardwareSerial& serial);
        virtual void run();
        bool isEnabled();
        void enable();
        void disable();
    private:
        bool enabled=true;
};

#endif
