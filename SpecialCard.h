#ifndef SPECIALCARD_H
#define SPECIALCARD_H

#include "Card.h"

class SpecialCard: public Card {
    public:
    SpecialCard(int point, std::string nameVal);
    virtual void applyEffect() = 0;

    private:
    const std::string name;
};


#endif // SPECIALCARD_H
