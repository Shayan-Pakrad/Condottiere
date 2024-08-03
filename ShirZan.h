#ifndef SHIRZAN_H
#define SHIRZAN_H
#include "SpecialCard.h"
#include "Player.h"

class ShirZan : public SpecialCard
{
public:
    ShirZan();
    void applyEffect(Player &player) override;
    virtual void applyEffect(Battle &battle) {};

private:
};

#endif // SHIRZAN_H