#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "Deck.h"
#include "Province.h"

class Game {
public:
    // Constructor
    Game();

    // Member functions
    void welcome() ; 
    void startGame();
    void initPlayers();
    void addPlayer(const Player& player);
    void sortPlayers();
    void showCards();
    void setNeshaneJang();


private:
    std::vector<Player> players; // List of the game players
    Map map;
    Deck deck;
    Province &NeshaneJangProvince; // The province that will be battle
};

#endif // GAME_H
