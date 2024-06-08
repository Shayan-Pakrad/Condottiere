#include "Battle.h"

// Constructor
Battle::Battle(Province *province, std::vector<Player> *players)
    : province(province), players(players) {}