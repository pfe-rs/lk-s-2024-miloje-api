#ifndef _BATTERY_H
#define _BATTERY_H

#include "Capability.h"
#include <Arduino.h>
#include <HardwareSerial.h>

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
