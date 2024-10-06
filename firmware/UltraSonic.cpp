#include "UltraSonic.h"

/**
* Speed of sound in meters per microsecond
*/
const float speedOfSound = 343.0 / 1000000.0;

/**
* Constructs an UltraSonic object.
* 
* @param trigPin The pin number used to trigger the ultrasonic pulse.
* @param echoPin The pin number used to receive the echo signal.
*/
UltraSonic::UltraSonic(int trigPin, int echoPin) : trigPin(trigPin), echoPin(echoPin) {}

/**
* Sets up the ultrasonic sensor.
* 
*/
void UltraSonic::setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

/**
* Decodes incoming instructions to measure distance.
* 
* @param strs Array of strings containing command parameters (not used in this function).
* @param serial Reference to the HardwareSerial object for serial communication.
*/
void UltraSonic::decode(String* strs,HardwareSerial& serial){
    float duration, distance;  
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW);  
    duration = pulseIn(echoPin, HIGH);
    distance = (duration * speedOfSound) / 2;  
    serial.println(distance);
}

/** 
* This method returns a character "U" representing the type of the ultra sonic sensor.
* 
* @return A character representing the ultra sonic's type ('U').
*/
char UltraSonic::type() {
    return 'U';
}
