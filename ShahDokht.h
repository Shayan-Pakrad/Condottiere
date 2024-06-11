#ifndef SHAHDOKHT_H
#define SHAHDOKHT_H

#include "SpecialCard.h"

class ShahDokht: public SpecialCard {
    public:
    ShahDokht();
    void applyEffect(Player &player) override {};
    private:
};


#endif // SHAHDOKHT_H