#ifndef RISHSEFID_H
#define RISHSEFID_H

#include "SpecialCard.h"

class RishSefid: public SpecialCard {
    public:
    RishSefid();
    void applyEffect(Battle &battle) override;
    virtual void applyEffect(Player &player) {};
    private:
};

#endif // RISHSEFID_H