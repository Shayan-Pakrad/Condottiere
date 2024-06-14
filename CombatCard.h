#ifndef COMBATCARD_H
#define COMBATCARD_H

#include "Card.h"

class CombatCard : public Card{
    public:
    CombatCard(int point); // Class constructor

    virtual void applyEffect(Player &player) override {};
    virtual void applyEffect(Battle &battle) override {};
    private:
};

#endif // COMBATCARD_H