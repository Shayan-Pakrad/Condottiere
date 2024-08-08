#include "Game.h"
#include <fstream>

// Constructor
Game::Game() : currentBattle(nullptr), winner(nullptr), NeshaneSolhSetter("N")
{
    welcome();

    std::cout << "1. New Game \n";
    std::cout << "2. Load Game \n";
    std::cout << "3. Exit \n\n";
    std::cout << "Your choice : ";

    int userInput;
bool Flag = true ; 
while (Flag)
{
    std::cin >> userInput;

    if (userInput == 1)
    {
        startGame(1);
        Flag = false ; 
    }
    else if (userInput == 2)
    {
        startGame(2);
        Flag = false ; 
    }
    else if (userInput == 3)
    {
        exit(0);
        Flag = false ; 
    }
    else{ 
        std::cout << "wrong input !!" <<std::endl; 
    }
}

}
// destructor
Game::~Game()
{
    if (currentBattle)
    {
        delete currentBattle;
    }
}

// Start the game by initializing and sorting players
void Game::startGame(int n)
{

    if (n == 1)
    {
        initPlayers();
        sortPlayers();
        showCards();
        while (true)
        {
            setNeshaneJangProvince();
            setKhoshShansiNumber();
            setBadShansiNumber();
            initiateBattle();
            if (checkForWinner() == true)
            {
                break;
            }
        }
        endGame();
    }

    else if (n == 2)
    {
        loadGame();
        while (true)
        {
            setNeshaneJangProvince();
            setKhoshShansiNumber();
            setBadShansiNumber();
            initiateBattle();
            if (checkForWinner() == true)
            {
                break;
            }
        }
        endGame();
    }
}

void Game::welcome()
{
    std::string welcomeText = R"(
 __        __         _                                       _____             _____   _                 ____                       _           _     _                             
 \ \      / /   ___  | |   ___    ___    _ __ ___     ___    |_   _|   ___     |_   _| | |__     ___     / ___|   ___    _ __     __| |   ___   | |_  (_)   ___   _ __   _ __    ___ 
  \ \ /\ / /   / _ \ | |  / __|  / _ \  | '_ ` _ \   / _ \     | |    / _ \      | |   | '_ \   / _ \   | |      / _ \  | '_ \   / _` |  / _ \  | __| | |  / _ \ | '__| | '__|  / _ \
   \ V  V /   |  __/ | | | (__  | (_) | | | | | | | |  __/     | |   | (_) |     | |   | | | | |  __/   | |___  | (_) | | | | | | (_| | | (_) | | |_  | | |  __/ | |    | |    |  __/
    \_/\_/     \___| |_|  \___|  \___/  |_| |_| |_|  \___|     |_|    \___/      |_|   |_| |_|  \___|    \____|  \___/  |_| |_|  \__,_|  \___/   \__| |_|  \___| |_|    |_|     \___|
                                                                                                                                                                                     
     
)";

    std::cout << welcomeText << std::endl;
    std::cout.flush(); // Flush output buffer
    std::cout << std::endl;
}

// Initialize players
void Game::initPlayers()
{
    std::cout << "Number of players: ";
    int numberOfPlayers;
    std::cin >> numberOfPlayers;

    for (int i = 0; i < numberOfPlayers; ++i)
    {
        // Get player name
        std::cout << "Player " << i + 1 << " name: ";
        std::string name;
        std::cin >> name;

        // Get player age
        std::cout << "Player " << i + 1 << " age: ";
        int age;
        std::cin >> age;

        // Get player color
        std::cout << "Player " << i + 1 << " color: ";
        std::string color;
        std::cin >> color;

        // Add new player to players list
        Player player{name, age, color};
        addPlayer(player);
    }
}

// Add player to the players list
void Game::addPlayer(const Player player)
{
    players.push_back(player);
}

// Sort players vector based on their age ( for initializing the first province to attack )
void Game::sortPlayers()
{
    int n = players.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (players[j].getAge() > players[j + 1].getAge())
            {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
    NeshaneJangSetter = players[0].getName();
    khoshShansiNumberSetter = players[0].getName();
    badShansiNumberSetter = players[0].getName();
}

void Game::showCards()
{
    int numberOfPlayers = players.size();
    for (int i = 0; i < numberOfPlayers; i++)
    {
        std::system("cls");

        std::cin.get();

        std::cout << "I Want Wo Show " << players[i].getName() << "'s Cards \n";
        std::cout << "Press ENTER To Continue!";

        std::cin.get();
        std::system("cls");

        deck.deal(players[i]);

        std::vector<std::shared_ptr<Card>> playerCards = players[i].getCardsInHand();
        std::cout << "Here is " << players[i].getName() << "'s cards :" << std::endl
                  << std::endl;
        for (int j = 0; j < playerCards.size(); j++)
        {
            std::cout << playerCards[j]->getName() << std::endl;
        }

        std::cout << std::endl
                  << "Press ENTER To Continue!";
        std::cin.get();
    }

    std::cout << std::endl
              << std::endl
              << std::endl;
    std::cout << "The Game Is About To Start ........! \n";
}

// A function for getting the neshanejang from the user (independent from the case size that user enters\)
void Game::setNeshaneJangProvince()
{

    system("cls");

    // Map of province names to enum values
    std::unordered_map<std::string, prov> provinceMap = {
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
        {"hemedan", HEMEDAN},
        };

    std::string NeshaneSolhProvince = "";

    if (NeshaneSolhSetter != "N")
    {

        std::cout << "( " << NeshaneSolhSetter << " )" << "should set Neshan Solh";
        std::cout << "HERE IS A LIST OF PROVNICES ----->  ";
        map.provinceListPrinter();
        std::cout << "Please Select The Province You Want The Neshane Solh To Be On  : " << std::endl;
        std::string InputProvince;

        // Check if the provinceName exists in the map
        bool flag = true;
        while (flag)
        {
            std::cin >> InputProvince;
            std::string lowerCaseProvinceName = InputProvince;
            std::transform(lowerCaseProvinceName.begin(), lowerCaseProvinceName.end(), lowerCaseProvinceName.begin(), ::tolower);
            if (provinceMap.find(lowerCaseProvinceName) != provinceMap.end())
            {

                // check if the province has been seleted before
                if (std::find(totalConqueredProvinces.begin(), totalConqueredProvinces.end(), lowerCaseProvinceName) != totalConqueredProvinces.end())
                {
                    std::cout << "This province has been conquered before \nTry another : ";
                    continue;
                }

                NeshaneSolhProvince = lowerCaseProvinceName;
                std::cout << "Neshane Solh set to province:      " << InputProvince << std::endl;
                flag = false;
            }
            else
            {
                std::cout << "Province not found. Neshane Solh not set." << std::endl;
            }
        }
    }

    std::cout << "( " << NeshaneJangSetter << " )" << "should set Neshan Jang";
    std::cout << "HERE IS A LIST OF PROVNICES ----->  ";
    map.provinceListPrinter();
    std::cout << "Please Select The Province You Want The War To Be On  : " << std::endl;

    std::string InputProvince;

    // Check if the provinceName exists in the map
    bool flag = true;
    while (flag)
    {
        std::cin >> InputProvince;
        std::string lowerCaseProvinceName = InputProvince;
        std::transform(lowerCaseProvinceName.begin(), lowerCaseProvinceName.end(), lowerCaseProvinceName.begin(), ::tolower);
        if (provinceMap.find(lowerCaseProvinceName) != provinceMap.end())
        {

            // check if the province has been seleted before
            if (std::find(totalConqueredProvinces.begin(), totalConqueredProvinces.end(), lowerCaseProvinceName) != totalConqueredProvinces.end())
            {
                std::cout << "This province has been conquered before \nTry another : ";
                continue;
            }

            if (NeshaneSolhProvince == lowerCaseProvinceName)
            {
                std::cout << "Neshane Solh is the same as Neshane Jang\n";
                continue;
            }

            totalConqueredProvinces.push_back(lowerCaseProvinceName);
            NeshaneJangProvince = provinceMap[lowerCaseProvinceName];
            std::cout << std::endl
                      << std::endl
                      << "NeshaneJang set to province:   " << std::endl
                      << InputProvince << " \nSo Whoever Wins The Round " << InputProvince << " Is Gonna Be In His Conquered Province List  " << std::endl
                      << std::endl
                      << std::endl;
            flag = false;
        }
        else
        {
            std::cout << "Province not found. NeshaneJang not set." << std::endl;
        }
    }

    khoshShansiNumberSetter = NeshaneJangSetter;
}
void Game::setKhoshShansiNumber()
{
    std::cout << "HINT----------> whatever point you get ....  if it is multiple of KHOSHSHANI number your point will be doubled and the end of the battle \n " << std::endl;
    std::cout << "((" << khoshShansiNumberSetter << "))" << " should set khosh-shansi number \n  Remember that the range of this number is (10) to (99) : \n"
              << std::endl;
    bool flag = true;
    while (flag)
    {
        std::cin >> khoshShansiNumber;
        if (khoshShansiNumber < 10 || khoshShansiNumber > 99)
        {
            std::cout << "WRONG NUMBER !!!!\n";
        }
        else
        {
            flag = false;
        }
    }
}
void Game::setBadShansiNumber()
{

    std::cout << std::endl
              << "HINT----------> whatever point you get ....   if it is multiple of BADSHANSI number you are gonna be eliminated from current battle  \n " << std::endl;
    std::cout << "((" << badShansiNumberSetter << "))" << "should set bad-shansi number \n  Remember that the range of this number is (10) to (99) : \n"
              << std::endl;
    bool flag = true;
    while (flag)
    {
        std::cin >> badShansiNumber;
        if (badShansiNumber < 10 || badShansiNumber > 99)
        {
            std::cout << "WRONG NUMBER !!!!\n";
        }
        else
        {
            flag = false;
        }
    }
}

bool Game::shirzanCounterIterator()
{

    greatestShirZan = players[0].getShirZanCounter();

    for (int i = 1; i < players.size(); i++)
    {
        if (players[i].getShirZanCounter() > greatestShirZan)
        {
            greatestShirZan = players[i].getShirZanCounter();
        }
    }
    bool isUnique = true;
    for (int i = 0; i < players.size(); i++)
    {
        if (greatestShirZan == players[i].getShirZanCounter())
        {
            isUnique = false;
        }
    }
    return isUnique;
}
int Game::getKhoshShansiNumber()
{
    return khoshShansiNumber;
}
int Game::getBadShansiNumber()
{
    return badShansiNumber;
}

void Game::initiateBattle()
{
    if (currentBattle)
    {
        delete currentBattle;
    }

    currentBattle = new Battle(map.getProvinceByIndex(int(NeshaneJangProvince)), players, deck, khoshShansiNumber, badShansiNumber, khoshShansiNumberSetter , KhoshBadSetted);
    currentBattle->startBattle();
    khoshShansiNumberSetter = currentBattle->endBattle();
    badShansiNumberSetter = currentBattle->endBattle();
    if (!shirzanCounterIterator())
    {
        NeshaneJangSetter = currentBattle->endBattle();
    }
    else
    {
        for (int i = 0; i < players.size(); i++)
        {
            if (greatestShirZan == players[i].getShirZanCounter())
            {
                NeshaneJangSetter = players[i].getName();
            }
        }
    }

    saveGame();

    NeshaneSolhSetter = currentBattle->getNeshaneSolhSetter();
}

bool Game::checkForWinner()
{
    for (auto &player : players)
    {
        if (player.winnerDeterminer())
        {
            winner = &player;
            return true;
        }
    }
    return false;
}

void Game::endGame()
{
    system("cls");
    std::cout << "\n\n\tPlayer " << winner->getName() << " has won the game!!";
}

void Game::saveGame()
{

    std::ofstream fout("game.txt");

    // number of players
    fout << players.size() << std::endl;

    // players names, ages, colors
    for (int i = 0; i < players.size(); i++)
    {
        fout << players[i].getName() << std::endl;
        fout << players[i].getAge() << std::endl;
        fout << players[i].getColor() << std::endl;
    }

    // number of player cards in hand
    for (int i = 0; i < players.size(); i++)
    {
        std::vector<std::shared_ptr<Card>> cards = players[i].getCardsInHand();
        int numberOfCards = cards.size();
        fout << numberOfCards << std::endl;
        for (int j = 0; j < numberOfCards; j++)
        {
            fout << cards[j]->getName() << std::endl;
        }
    }
    // players provinces
    for (int i = 0; i < players.size(); i++)
    {
        std::vector<Province> provinces = players[i].getConqueredProvinces();
        int numberOfProvinces = provinces.size();
        fout << numberOfProvinces << std::endl;
        for (int j = 0; j < numberOfProvinces; j++)
        {
            std::string lowerCaseProvinceName = provinces[j].getName();
            std::transform(lowerCaseProvinceName.begin(), lowerCaseProvinceName.end(), lowerCaseProvinceName.begin(), ::tolower);
            fout << provinceMap[lowerCaseProvinceName] << std::endl;
        }
    }

    // NeshaneJangSetter
    fout << NeshaneJangSetter << std::endl;

    fout.close();
}

void Game::loadGame()
{

    std::ifstream fin("game.txt");

    int NumberOfPlayers;

    if (fin.is_open())
    {

        // number of players
        fin >> NumberOfPlayers;

        // some variables to use in for loops
        std::string name, color;
        int age;
        int numberOfCards;
        std::string cardName;
        int numberOfProvinces, province;

        // players names, ages, colors
        for (int i = 0; i < NumberOfPlayers; i++)
        {
            fin >> name;
            fin >> age;
            fin >> color;
            Player player{name, age, color};
            addPlayer(player);
        }

        // cards in hand
        for (int i = 0; i < NumberOfPlayers; i++)
        {
            fin >> numberOfCards;
            for (int j = 0; j < numberOfCards; j++)
            {
                fin >> cardName;
                deck.dealCrad(players[i], cardName);
            }
        }

        // provinces
        for (int i = 0; i < NumberOfPlayers; i++)
        {
            fin >> numberOfProvinces;
            for (int j = 0; j < numberOfProvinces; j++)
            {
                fin >> province;
                std::cout << std::endl
                          << province << std::endl;
                players[i].addProvince(map.getProvinceByIndex(int(province)));

                std::string lowerCaseProvinceName = map.getProvinceByIndex(int(province)).getName();
                std::transform(lowerCaseProvinceName.begin(), lowerCaseProvinceName.end(), lowerCaseProvinceName.begin(), ::tolower);
                totalConqueredProvinces.push_back(lowerCaseProvinceName);
            }
        }

        // NeshaneJangSetter
        fin >> NeshaneJangSetter;

        fin.close();
    }

    else
    {
        std::cout << "there is no saved game!! play a new game";
        exit(0);
    }
}
