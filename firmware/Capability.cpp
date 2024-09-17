#include "Capability.h"

void Capability::setup() {}

void Capability::run() {}

bool Capability::isEnabled() {
    return enabled;
}

void Capability::enable() {
    enabled = true;
}
void Capability::disable() {
    enabled = false;
}
