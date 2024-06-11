#include "Zemestan.h"

Zemestan::Zemestan(): SpecialCard(0, "zemestan") {}

void Zemestan::applyEffect(Battle &battle) {
    battle.zemestanSwitch();
}