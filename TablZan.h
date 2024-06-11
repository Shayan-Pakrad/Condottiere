#ifndef TABLZAN_H
#define TABLZAN_H

#include "SpecialCard.h"

class TablZan: public SpecialCard {
    public:
    TablZan();
    void applyEffect(Player &player) override;
    private:
};


#endif // TABLZAN_H