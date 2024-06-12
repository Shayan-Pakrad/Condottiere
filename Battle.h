#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include "Province.h"
#include "Player.h"

class Battle {
public:
    // Constructor
    Battle(Province &province, std::vector<Player> &players);
    void baharSwitch(); // If bahar has played
    void zemestanSwitch(); // If Zemestan has played

private:
    Province &province;
    std::vector<Player> &players;
    bool baharHasPlayed;
    bool ZemestanHasPlayed;
};

#endif // BATTLE_H