#ifndef BAHAR_H
#define BAHAR_H

#include "SpecialCard.h"

class Bahar: public SpecialCard {
    public:
    Bahar();
    void applyEffect(Battle &battle) override;
    virtual void applyEffect(Player &player) {};
    private:
};

#endif // BAHAR_H