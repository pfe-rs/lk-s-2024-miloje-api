#include "Communication.h"

Communication::Communication(
  HardwareSerial& serial,
  Capability* capabilities[],
  int numCapabilities
) : serial(serial), capabilities(capabilities), numCapabilities(numCapabilities) {}

void Communication::commSetup(int baudRate) {
  serial.begin(baudRate);
  for(int i = 0; i < numCapabilities; i++)
    capabilities[i]->setup();
  for(int i = 0; i < numCapabilities; i++) {
    if(capabilities[i]->type() == 'B') {
      batteryId = i;
      break;
    }
  }
}

void Communication::getCapabilities() {
  String listCapabilities = "";
  for(int i = 0; i < numCapabilities; i++)
    listCapabilities += (capabilities[i]->type());
  serial.println(listCapabilities);
}

void Communication::decode(String *strs) {
  int id = strs[0].toInt();
  capabilities[id]->decode(strs + 1, serial);
}

void Communication::commLoop() {
  float batteryLevel = capabilities[batteryId]->checkLevel();
  if(batteryLevel <= 11 && batteryLevel >= 2) {
    tone(6, 880);
    delay(100);
    tone(6, 440);
    delay(100);
    noTone(6);
    delay(20);
  }

  String str, strs[20];
  if (serial.available() > 0) {
    str = serial.readStringUntil('\n');
  }

  serial.println(str);
  
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

  if(StringCount != 0)
    decode(strs);
}
