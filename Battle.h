#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include "Province.h"
#include "Player.h"

class Battle {
public:
    // Constructor
    Battle(Province *province, std::vector<Player> *players);

private:
    Province *province;
    std::vector<Player> *players;
};

#endif // BATTLE_H