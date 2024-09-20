#ifndef _BATTERY_H
#define _BATTERY_H

#include "Capability.h"
#include <Arduino.h>
#include <HardwareSerial.h>

/**
* Battery is a class that looks over the pin off of which we read the voltage that the battery is giving to MILOJE.
* It is one of the capabilities.
*/

class Battery : public Capability {
    public:
        Battery(int pin);
        void decode(String *strs, HardwareSerial& serial) override;
        float getLevel();
        char type() override;
    private:
        int pin;
};

#endif
