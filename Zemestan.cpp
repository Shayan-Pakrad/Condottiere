#include "Zemestan.h"
//Ability :All of Combat cards will be 1 after this  (Tablzan has it's effect after Zemestan) 
Zemestan::Zemestan(): SpecialCard(0, "zemestan") {}

void Zemestan::applyEffect(Battle &battle) {
    battle.zemestanSwitch();
}