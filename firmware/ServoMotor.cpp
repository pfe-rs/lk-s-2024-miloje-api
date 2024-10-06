#include "ServoMotor.h"

/**
* Constructs a ServoMotor object.
*
* @param pin The pin number to which the servo motor is connected.
*/
ServoMotor::ServoMotor(int pin) : pin(pin) {}

/**
* Sets up the servo motor.
*/
void ServoMotor::setup() {
    servo.attach(pin); 
}

/**
* Decodes incoming instructions to set the servo's position.
*
* @param strs Array of strings containing the command parameters.
* @param serial Reference to the HardwareSerial object for serial communication.
*/
void ServoMotor::decode(String* strs, HardwareSerial& serial) {
    setPosition(strs[0].toInt());
}

/**
* Sets the position of the servo motor.
* 
* @param pos The position to which the servo motor should be set in degrees 0-180.
*/
void ServoMotor::setPosition(int pos) {
    servo.write(pos);
}

/** 
* This method returns a character "S" representing the type of the servo motor.
* 
* @return A character representing the servo motor's type ('S').
*/
char ServoMotor::type() {
    return 'S';
}