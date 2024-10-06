#include "Communication.h"

/**
* Constructs a Communication object.
* 
* @param serial Reference to the HardwareSerial object used for serial communication.
* @param capabilities Array of pointers to Capability objects representing MILOJE's capabilities.
* @param numCapabilities The number of capabilities in the array.
*/
Communication::Communication(
    HardwareSerial& serial,
    Capability* capabilities[],
    int numCapabilities
) : serial(serial), capabilities(capabilities), numCapabilities(numCapabilities) {}

/**
* Initializes the serial communication at a specified baud rate.
* Sets up each capability by callin its setup method. 
*
* @param baudRate The baud rate for serial communication.
*/
void Communication::commSetup(int baudRate) {
    serial.begin(baudRate);
    for(int i = 0; i < numCapabilities; i++)
        capabilities[i]->setup();
}

/**
* Sends a list of available capabilities over the serial connection.
* 
* The capabilities are represented as a string of their types.
*/
void Communication::getCapabilities() {
    String listCapabilities = "";
    for(int i = 0; i < numCapabilities; i++)
        listCapabilities += (capabilities[i]->type());
    serial.println(listCapabilities);
}

/**
* Decodes incoming instructions from a string array.
* 
* @param strs Array of strings containing the incoming command and its parameters.
*/
void Communication::decode(String *strs) {
    if(strs[0]=="C")
        getCapabilities();
    else {
        int id = strs[0].toInt();
        if(capabilities[id]->isEnabled())
            capabilities[id]->decode(strs + 1, serial);
    }
}

/**
* @brief Main loop for processing incoming instructions.
* 
* This function checks for available serial data, reads it into a string, 
* and splits it into an array of strings. It then decodes the command and
* executes the run method of all capabilities.
*/
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
