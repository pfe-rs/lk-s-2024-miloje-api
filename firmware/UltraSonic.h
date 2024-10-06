#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H
#include "Capability.h"

/**
* UltraSonic is a class for the ultra sonic sensor, which is one of the capabilities.
*/

class UltraSonic : public Capability {
    public:
        UltraSonic(int trigPin, int echoPin);
        void setup() override;
        void decode(String* strs,HardwareSerial& serial) override;
        char type() override;
    private:
        int trigPin, echoPin;
};

#endif
