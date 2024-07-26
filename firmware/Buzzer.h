#ifndef _BUZZER_H
#define _BUZZER_H
#include "Capability.h"

class Buzzer : public Capability {
    public:
        Buzzer(int pin);
        void decode(String* strs, HardwareSerial& serial) override;
        void run() override;
        char type() override;
    private:
        int pin;
};

#endif
