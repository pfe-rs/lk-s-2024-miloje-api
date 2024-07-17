#include "Communication.h"

const int step_left_pin = 11;
const int step_right_pin = 12;
const int dir_left_pin = 50;
const int dir_right_pin = 47;
const int servo_down_pin = 2;
const int servo_up_pin = 3;
const int ultra_pin_trig = 4;
const int ultra_pin_echo = A0;
HardwareSerial& SERIAL_UART = Serial;
HardwareSerial& SERIAL_BLUETOOTH = Serial3;

Communication comm(SERIAL_UART, servo_up_pin, servo_down_pin, ultra_pin_trig, ultra_pin_echo, step_left_pin, dir_left_pin, step_right_pin, dir_right_pin);

void setup() {
  comm.Setup();
}

void loop()
{
  comm.Loop();
  delay(500);
}
