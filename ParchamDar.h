#ifndef PARCHAMDAR_H
#define PARCHAMDAR_H

#include "SpecialCard.h"

class ParchamDar: public SpecialCard {
    public:
    ParchamDar();
    void applyEffect(Player &player)override ; 
    virtual void applyEffect(Battle &battle) {};
    private:
};

#endif // PARCHAMDAR_H