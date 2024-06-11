#include "Card.h"

// Initialize the arrays in the constructor
Card::Card(int point, std::string name) {
    this->point = point;
    this->name = name;
}

// Set the point value
void Card::setPoint(int p) {
    point = p;
}

// Get the point value
int Card::getPoint() const {
    return point;
}

void Card::setType(std::string type) {
    this->type = type;
}

std::string Card::getType() const {
    return type;
}

std::string Card::getName() const {
    return name;
}

