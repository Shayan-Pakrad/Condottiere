#ifndef ZEMESTAN_H
#define ZEMESTAN_H

#include "SpecialCard.h"

class Zemestan: public SpecialCard {
    public:
    Zemestan();
    void applyEffect(Battle &battle) override;
    virtual void applyEffect(Player &player) {};
    private:
};

#endif // ZEMESTAN_H