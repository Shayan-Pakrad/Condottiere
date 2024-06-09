#ifndef COMBATCARD_H
#define COMBATCARD_H

#include "Card.h"

class CombatCard : public Card{
    public:
    CombatCard(int point, int cardNumber); // Class constructor
    private:
    const int cardNumber; // Number on the card and it's const
};

#endif // COMBATCARD_H