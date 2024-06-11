#ifndef SPECIALCARD_H
#define SPECIALCARD_H

#include "Card.h"
#include "Player.h"

class SpecialCard: public Card {
    public:
    SpecialCard(int point, std::string name);
    virtual void applyEffect(Player &player) = 0;
    private:
};


#endif // SPECIALCARD_H
