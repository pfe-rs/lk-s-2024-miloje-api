#ifndef _BUZZER_H
#define _BUZZER_H
#include "Capability.h"

class Buzzer : public Capability {
    public:
        Buzzer(int pin);
        void decode(String* strs, HardwareSerial& serial) override;
        void setup() override;
        void buzz(int frequency);
        char type() override;
    private:
        int pin;
};

#endif
