#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <unordered_map>



#include "Player.h"
#include "Map.h"
#include "Deck.h"
#include "Province.h"

class Game {
public:
    // Constructor and destructor
    Game();
    ~Game();

    // Member functions
    void welcome();
    void startGame();
    void initPlayers();
    void addPlayer(const Player& player);
    void sortPlayers();
    void showCards();
    void setNeshaneJangProvince();
    void initiateBattle();

    // Enum for provinces (any input as province's string will be an integer index )
    enum prov {
        BELLA = 0,
        CALINE = 1,
        ENNA = 2,
        ATELA = 3,
        PLADACI = 4, 
        BORGE = 5,
        DIMASE = 6,
        MORINA = 7,
        OLIVIA = 8,
        ROLLO = 9,
        TALMONE = 10, 
        ARMENTO = 11,
        LIA = 12,
        ELINA = 13  
    };

private:
    std::vector<Player> players; // List of the game players
    Map map;
    Deck deck;
    prov NeshaneJangProvince;

    Battle *currentBattle;
    
};

#endif // GAME_H
