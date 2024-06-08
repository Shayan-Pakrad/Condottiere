#include "Province.h"

// Constructor
Province::Province() : conquered(false) {}

// Setter for name
void Province::setName(const std::string& n) {
    name = n;
}

// Getter for name
std::string Province::getName() const {
    return name;
}