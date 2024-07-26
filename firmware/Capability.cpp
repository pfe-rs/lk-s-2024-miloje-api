#include "Capability.h"

void Capability::setup() {}

void Capability::run() {}

bool Capability::isEnabled() {
    return this->enabled;
}

void Capability::enable() {
    this->enabled = true;
}
void Capability::disable() {
    this->enabled = false;
}
