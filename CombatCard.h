#ifndef COMBATCARD_H
#define COMBATCARD_H

#include "Card.h"

class CombatCard : public Card{
    public:
    CombatCard(int point); // Class constructor

    virtual void applyEffect(Player &player) {};
    virtual void applyEffect(Battle &battle) {};
    private:
};

#endif // COMBATCARD_H