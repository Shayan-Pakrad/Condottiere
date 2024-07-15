#include "RishSefid.h"
RishSefid::RishSefid(): SpecialCard(0, "rishsefid") {}

void RishSefid::applyEffect(Battle &battle) {
    battle.RishSefidSwitch();
}