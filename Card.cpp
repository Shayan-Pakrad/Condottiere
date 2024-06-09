#include "Card.h"

// Initialize the arrays in the constructor
Card::Card(int point) {
    this->point = point;
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

