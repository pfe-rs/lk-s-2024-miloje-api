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
  String *strs2 = new String[1];
  strs2[0] = "1";
  capabilities[2]->decode(strs2, serial);
  //serial.println("rista dvadeset karaktera jos malo");
  //getCapabilities();
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

  if(StringCount != 0)
    decode(strs);
}
