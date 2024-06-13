#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "Deck.h"

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

private:
    std::vector<Player> players; // List of the game players
    Map map;
    Deck deck;
};

#endif // GAME_H
