#include "TablZan.h"
//Ability : Doubles the point of combat cards 
TablZan::TablZan(): SpecialCard(0, "tablzan") {}

void TablZan::applyEffect(Player &player) {
    player.tablZanSwitch();
}