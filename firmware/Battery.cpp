#include "Battery.h"

/**
* Resolution of the ADC (10-bit)
*/
const float ADCResolution = 1024.0;
/**
* Voltage reference of the Arduino
*/
const float arduinoVoltage  = 5.0;
/**
* Offset for accurate battery level measurement
*/
const float measurementOffset = 0.7;

/**
* Constructor for the Battery class.
* 
* @param pin The pin number used for reading the battery voltage.
*/
Battery::Battery(int pin) : pin(pin) {}

/**
* This method reads the battery level and sends it over the 
* provided serial.
* 
* @param strs Pointer to an array of strings that were used as an input (not used in this method).
* @param serial Reference to a HardwareSerial object for serial communication.
*/
void Battery::decode(String* strs, HardwareSerial& serial) {
    serial.println(getLevel());
}

/**
* This method reads the analog value from the specified pin,
* converts it to a voltage level, and applies an offset for accuracy.
* 
* @return The calculated battery voltage level.
*/
float Battery::getLevel() {
    return (float(analogRead(pin)) / ADCResolution) * 3 * arduinoVoltage + measurementOffset;
}

/** 
* This method returns a character "B" representing the type of the buzzer.
* 
* @return A character representing the buzzer type ('B').
*/
char Battery::type() {
    return 'B';
}
