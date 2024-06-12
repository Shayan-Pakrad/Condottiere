#ifndef SHAHDOKHT_H
#define SHAHDOKHT_H

#include "SpecialCard.h"

class ShahDokht: public SpecialCard {
    public:
    ShahDokht();
    void applyEffect(Player &player) override {};
    virtual void applyEffect(Battle &battle) {};
    private:
};


#endif // SHAHDOKHT_H