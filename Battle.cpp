#include "Battle.h"

// Constructor
Battle::Battle(Province &province, std::vector<Player> &players)
    : province(province), players(players), baharHasPlayed(false), 
    ZemestanHasPlayed(false) {}

// bahar and zemestan switch
void Battle::baharSwitch() {
    baharHasPlayed = true;
    ZemestanHasPlayed = false;
}

void Battle::zemestanSwitch() {
    ZemestanHasPlayed = true;
    baharHasPlayed = false;
}