#ifndef ZEMESTAN_H
#define ZEMESTAN_H

#include "SpecialCard.h"

class Zemestan: public SpecialCard {
    public:
    Zemestan();
    void applyEffect(Battle &battle) override;
    private:
};

#endif // ZEMESTAN_H