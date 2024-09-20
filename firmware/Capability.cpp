#include "Capability.h"

/**
* This method is intended for initialization tasks specific to derived classes.
* It is currently empty and should be overridden in subclasses.
*/
void Capability::setup() {}

/**
* This method is intended for executing the capability's main logic.
* It is currently empty and should be overridden in subclasses.
*/
void Capability::run() {}

/**
* This method returns the current state of the capability's enabled status.
* 
* @return true if the capability is enabled, false otherwise.
*/
bool Capability::isEnabled() {
    return enabled;
}

/**
* This method sets the enabled state of the capability to true.
*/
void Capability::enable() {
    enabled = true;
}

/**
* This method sets the enabled state of the capability to false.
*/
void Capability::disable() {
    enabled = false;
}
