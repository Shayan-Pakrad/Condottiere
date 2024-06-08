#include "Card.h"

// Initialize the arrays in the constructor
Card::Card() {
    Special = {"ZEMESTAN", "BAHAR", "TABL-ZAN", "SHIR-ZAN", "SHAH-DOKHT", "MATARSAK", "PARCHAMDAR"};
    Mercenary = {"y1", "y2", "y3", "y4", "y5", "y6", "y10"};
}

// Set the point value
void Card::setPoint(int p) {
    point = p;
}

// Get the point value
int Card::getPoint() const {
    return point;
}

