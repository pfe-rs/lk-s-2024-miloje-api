#include "Communication.h"

Communication::Communication(
    HardwareSerial& serial,
    Capability* capabilities[],
    int numCapabilities
) : serial(serial), capabilities(capabilities), numCapabilities(numCapabilities) {}

// Start listening on the serial
void Communication::commSetup(int baudRate) {
    serial.begin(baudRate);
    for(int i = 0; i < numCapabilities; i++)
        capabilities[i]->setup();
}

 // Return list of capabilities (in a string)
void Communication::getCapabilities() {
    String listCapabilities = "";
    for(int i = 0; i < numCapabilities; i++)
        listCapabilities += (capabilities[i]->type());
    serial.println(listCapabilities);
}

// Decoder of the incoming instruction
void Communication::decode(String *strs) {
    if(strs[0]=="C")
        getCapabilities();
    else {
        int id = strs[0].toInt();
        if(capabilities[id]->isEnabled())
            capabilities[id]->decode(strs + 1, serial);
    }
}

// Loop for checking incoming instructions
void Communication::commLoop() {
    String str, strs[20];
    if (serial.available() > 0) {
        str = serial.readStringUntil('\n'); 
    }
    int stringCount = 0;
    while (str.length() > 0) {
            int index = str.indexOf(' ');
        if (index == -1) {
            strs[stringCount++] = str;
        break;
        }
        else {
            strs[stringCount++] = str.substring(0, index);
            str = str.substring(index + 1);
        }
    }
    if(stringCount != 0){
        decode(strs);
    }
    for(int id = 0; id < numCapabilities; id++) {
        capabilities[id]->run();
    }
}
