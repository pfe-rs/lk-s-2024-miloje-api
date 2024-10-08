#include "UltraSonic.h"

// Meters per second into meters per microsecond
const float speedOfSound = 343.0 / 1000000.0;

UltraSonic::UltraSonic(int trigPin, int echoPin) :
    trigPin(trigPin), echoPin(echoPin) {}

void UltraSonic::setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

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

char UltraSonic::type() {
    return 'U';
}
