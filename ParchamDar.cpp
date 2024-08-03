#include "ParchamDar.h"

ParchamDar::ParchamDar() : SpecialCard(0, "parchamdar") {}
void ParchamDar::applyEffect(Player &player) {};
void applyEffect(Battle &battle) {
    battle.endBattle () ;
};
