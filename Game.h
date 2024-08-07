#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <unordered_map>

#include "Player.h"
#include "Map.h"
#include "Deck.h"
#include "Province.h"
// Enum for provinces (any input as province's string will be an integer index )
enum prov
{
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
    ELINA = 13,
    HEMEDAN = 14
};
static std::unordered_map<std::string, prov> provinceMap =
    {
        {"bella", BELLA},
        {"caline", CALINE},
        {"enna", ENNA},
        {"atela", ATELA},
        {"pladaci", PLADACI},
        {"borge", BORGE},
        {"dimase", DIMASE},
        {"morina", MORINA},
        {"olivia", OLIVIA},
        {"rollo", ROLLO},
        {"talmone", TALMONE},
        {"armento", ARMENTO},
        {"lia", LIA},
        {"elina", ELINA},
        {"hemedan", HEMEDAN}};

class Game
{
public:
    // Constructor and destructor
    Game();
    ~Game();
    // Member functions
    void welcome();
    void startGame(int n);
    void initPlayers();
    void addPlayer(const Player player);
    void sortPlayers();
    void showCards();
    void setNeshaneJangProvince(); // also handle neshane solh
    void setKhoshShansiNumber();
    void setBadShansiNumber();
    void initiateBattle();
    bool checkForWinner();
    void endGame();
    bool shirzanCounterIterator();
    int getKhoshShansiNumber();
    int getBadShansiNumber();

    void saveGame();
    void loadGame();


private:
    std::vector<Player> players; // List of the game players
    Map map;
    Deck deck;

    int khoshShansiNumber;
    int badShansiNumber;
    prov NeshaneJangProvince;
    std::string khoshShansiNumberSetter;
    std::string badShansiNumberSetter;
    std::string NeshaneJangSetter; // Player name
    std::string NeshaneSolhSetter; // it would be "N" if nobody play RishSefid
    int greatestShirZan;
    std::vector<std::string> totalConqueredProvinces; // provinces that has conquered by players
bool KhoshBadSetted = false  ;
    Battle *currentBattle;

    Player *winner;
};

#endif // GAME_H
