#include "TablZan.h"

TablZan::TablZan(): SpecialCard(0, "tablzan") {}

void TablZan::applyEffect(Player &player) {
    player.tablZanSwitch();
}