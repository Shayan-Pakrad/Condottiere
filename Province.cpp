#include "Province.h"

// Constructor
Province::Province() : conquered(false) {}
Province::Province(const std::string& n) : name(n), conquered(false) {}//A constructor for initializing provinces name in Map.cpp

// Setter for name
void Province::setName(const std::string& n) {
    name = n;
}

// Getter for name
std::string Province::getName() const {
    return name;
}