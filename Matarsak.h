#ifndef MATARSAK_H
#define MATARSAK_H

#include "SpecialCard.h"

class Matarsak: public SpecialCard {
    public:
    Matarsak();
    void applyEffect(Player &player) override;
    private:
};

#endif // MATARSAK_H