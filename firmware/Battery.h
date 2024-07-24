#ifndef _BATTERY_H
#define _BATTERY_H
#include "Capability.h"

class Battery : public Capability {
    public:
        Battery();
        void decode(String* strs, HardwareSerial& serial) override;
        float checkLevel() override;
        char type() override;
};

#endif