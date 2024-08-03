#include "ShirZan.h"
// Ability : Who ever plays this special card can set the Neshane-Jang for the next province to have a fight on
ShirZan::ShirZan() : SpecialCard(1, "shirzan") {}

void ShirZan::applyEffect(Player &player)
{
    player.setShirzanCounter();
    // player.getShirZan(); 
}
