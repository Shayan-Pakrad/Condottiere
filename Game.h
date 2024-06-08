#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "Map.h"

class Game {
public:
    // Constructor
    Game();

    // Member functions
    void startGame();
    void initPlayers();
    void addPlayer(const Player& player);
    void sortPlayers();

private:
    std::vector<Player> players; // List of the game players
    Map map;
};

#endif // GAME_H
