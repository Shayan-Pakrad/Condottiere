#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include "Province.h"
#include "Player.h"

class Deck; // forward declaration

class Battle {
public:
    // Constructor
    Battle(Province &province, std::vector<Player> &players, Deck &deck);
    void baharSwitch(); // If bahar has played
    void zemestanSwitch(); // If Zemestan has played
    void printInformation(); // Played cards and players provinces
    void startBattle();
    std::string endBattle();
    void resetPlayers(); // For future implementation not at midterm

    void checkPlayersHands(); // Check players have cards
    
    

private:

    Province &province;
    std::vector<Player> &players;
    Deck &deck;
    bool baharHasPlayed;
    bool zemestanHasPlayed;

};

#endif // BATTLE_H