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
    void RishSefidSwitch(); // If Rishsefid has played
    void printInformation(); // Played cards and players provinces
    void startBattle();
    std::string endBattle();
    void resetPlayers(); // Reset players after each battle

    void checkPlayersHands(); // Check players have cards

    std::string getNeshaneSolhSetter() const;
    
private:

    Province &province;
    std::vector<Player> &players;
    Deck &deck;
    bool baharHasPlayed;
    bool zemestanHasPlayed;
    bool RishSefidHasPlayed;

    std::string NeshaneSolhSetter; // the last player name who played RishSefid would have the NeshaneSolh

};

#endif // BATTLE_H