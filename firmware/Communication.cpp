#include "Communication.h"

Communication::Communication(
  HardwareSerial& serial,
  Capability* capabilities[]
) : serial(serial), capabilities(capabilities), numCapabilities(sizeof(capabilities) / sizeof(Capability*)) {}

void Communication::commSetup(int baudRate) {
  serial.begin(baudRate);
  serial.println(numCapabilities);
}

void Communication::getCapabilities() {
  String listCapabilities = "";
  for(int i = 0; i < numCapabilities; i++)
    listCapabilities += (capabilities[i]->type());
  serial.println(listCapabilities);
}

void Communication::decode(String *strs) {
  int id = strs[0].toInt();
  capabilities[id]->decode(strs + 1);
}

void Communication::commLoop() {
  String str, strs[20];
  if (serial.available() > 0) {
    str = serial.readString();
  }
  
  int StringCount = 0;
  while (str.length() > 0) {
    int index = str.indexOf(' ');
    if (index == -1) {
      strs[StringCount++] = str;
      break;
    } else {
      strs[StringCount++] = str.substring(0, index);
      str = str.substring(index + 1);
    }
  }

  decode(strs);
}