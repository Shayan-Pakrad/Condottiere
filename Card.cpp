#include "Card.h"

// Set the point value
void Card::setPoint(int p) {
    point = p;
}

// Get the point value
int Card::getPoint() const {
    return point;
}

// Initialize the arrays in the constructor
Card::Card()
    : Mercenary{{"y1", "y2", "y3", "y4", "y5", "y6", "y10"}},
      Special{{"ZEMESTAN", "BAHAR", "TABL-ZAN", "SHIR-ZAN", "SHAH-DOKHT", "MATARSAK", "PARCHAMDAR"}} {}
