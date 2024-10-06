#include "Buzzer.h"

/**
* Constructor for the Buzzer class.
* 
* @param pin The pin number to which the buzzer is connected.
*/
Buzzer::Buzzer(int pin) : pin(pin) {}

/**
* Sets up the pin mode for the buzzer.
*/
void Buzzer::setup() {
    pinMode(pin, OUTPUT);
}

/**
* This method is a placeholder for decoding functionality. 
* Currently, it will buzz at a frequency of 880 Hz.
* 
* @param strs Pointer to an array of strings that were used as an input (not used in this method).
* @param serial Reference to a HardwareSerial object for serial communication (not used in this method).
*/
void Buzzer::decode(String* strs, HardwareSerial& serial) {
    buzz(880);
}

/**
* This method plays a tone on the buzzer at the given frequency with a melody
* 
* @param frequency The frequency of the tone in Hertz.
*/
void Buzzer::buzz(int frequency) {
    tone(pin, frequency);
    delay(100);
    tone(pin, frequency/2);
    delay(100);
    noTone(pin);
    delay(20);
}

/** 
* This method returns a character "Z" representing the type of the buzzer.
* 
* @return A character representing the buzzer type ('Z').
*/
char Buzzer::type() {
    return 'Z';
}
