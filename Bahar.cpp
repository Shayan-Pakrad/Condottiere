#include "Bahar.h"

Bahar::Bahar(): SpecialCard(0, "bahar") {}

void Bahar::applyEffect(Battle &battle) {
    battle.baharSwitch();
}