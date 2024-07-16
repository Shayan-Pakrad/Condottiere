#include "Game.h"

// Constructor
Game::Game(): currentBattle(nullptr), winner(nullptr), NeshaneSolhSetter("N") {
    startGame();
}
// destructor
Game::~Game() {
    if (currentBattle) {
        delete currentBattle;
    }
}

// Start the game by initializing and sorting players
void Game::startGame() {
    welcome();
    initPlayers();
    sortPlayers();
    showCards();
    while (true) {
        setNeshaneJangProvince();
        initiateBattle();
        if (checkForWinner() == true){
            break;
        }
    }
    endGame();
    
}

void Game::welcome() {
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
void Game::initPlayers() {
    std::cout << "Number of players: ";
    int numberOfPlayers;
    std::cin >> numberOfPlayers;

    for (int i = 0; i < numberOfPlayers; ++i) {
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
void Game::addPlayer(const Player& player) {
    players.push_back(player);
}

// Sort players vector based on their age ( for initializing the first province to attack )
void Game::sortPlayers() {
    int n = players.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (players[j].getAge() > players[j + 1].getAge()) {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
    NeshaneJangSetter = players[0].getName();
}

void Game::showCards() {
    int numberOfPlayers = players.size();
    for (int i = 0; i < numberOfPlayers; i++) {
        std::system("cls");

        std::cin.get();

        std::cout << "I Want Wo Show " << players[i].getName() << "'s Cards \n";
        std::cout << "Press ENTER To Continue!";

        std::cin.get();
        std::system("cls");

        deck.deal(players[i]);

        std::vector<std::shared_ptr<Card>> playerCards = players[i].getCardsInHand();
        std::cout << "Here is " << players[i].getName() << "'s cards :" << std::endl << std::endl;
        for(int j = 0; j < playerCards.size(); j++) {
            std::cout << playerCards[j]->getName() << std::endl;
            
        }

        std::cout << std::endl << "Press ENTER To Continue!";
        std::cin.get();

    }
    
    std::cout <<std::endl <<std::endl<<std::endl;
    std::cout << "The Game Is About To Start ........! \n";    
    
}

// A function for getting the neshanejang from the user (independent from the case size that user enters\)
void Game::setNeshaneJangProvince(){

    system("clear");

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
        {"elina", ELINA}
    };

    std::string NeshaneSolhProvince = "";

    if (NeshaneSolhSetter != "N") {

        std::cout << "( " << NeshaneSolhSetter << " )" << "should set Neshan Solh";
        std::cout << "HERE IS A LIST OF PROVNICES ----->  ";
        map.provinceListPrinter();
        std::cout << "Please Select The Province You Want The Neshane Solh To Be On  : "<<std::endl;
        std::string InputProvince ;

        // Check if the provinceName exists in the map
        bool flag = true; 
        while (flag)
        {
        std::cin>> InputProvince ;
        std::string lowerCaseProvinceName = InputProvince;
        std::transform(lowerCaseProvinceName.begin(), lowerCaseProvinceName.end(), lowerCaseProvinceName.begin(), ::tolower);
        if (provinceMap.find(lowerCaseProvinceName) != provinceMap.end()) {

            // check if the province has been seleted before 
            if (std::find(totalConqueredProvinces.begin(), totalConqueredProvinces.end(), lowerCaseProvinceName) != totalConqueredProvinces.end()) {
                std::cout << "This province has been conquered before \nTry another : ";
                continue;
            }
            
            NeshaneSolhProvince = lowerCaseProvinceName;
            std::cout << "Neshane Solh set to province:      " << InputProvince << std::endl;
            flag = false ; 
        } else {
            std::cout << "Province not found. Neshane Solh not set." << std::endl;
        }
            
        }

    }

    std::cout << "( " << NeshaneJangSetter << " )" << "should set Neshan Jang";
    std::cout << "HERE IS A LIST OF PROVNICES ----->  ";
    map.provinceListPrinter();
    std::cout << "Please Select The Province You Want The War To Be On  : "<<std::endl;

    std::string InputProvince ;

    // Check if the provinceName exists in the map
    bool flag = true ; 
    while (flag)
    {
    std::cin>> InputProvince ;
    std::string lowerCaseProvinceName = InputProvince;
    std::transform(lowerCaseProvinceName.begin(), lowerCaseProvinceName.end(), lowerCaseProvinceName.begin(), ::tolower);
    if (provinceMap.find(lowerCaseProvinceName) != provinceMap.end()) {

        // check if the province has been seleted before 
        if (std::find(totalConqueredProvinces.begin(), totalConqueredProvinces.end(), lowerCaseProvinceName) != totalConqueredProvinces.end()) {
            std::cout << "This province has been conquered before \nTry another : ";
            continue;
        }

        if (NeshaneSolhProvince == lowerCaseProvinceName) {
            std::cout << "Neshane Solh is the same as Neshane Jang\n";
            continue;
        }
        

        totalConqueredProvinces.push_back(lowerCaseProvinceName);
        NeshaneJangProvince = provinceMap[lowerCaseProvinceName];
        std::cout << "NeshaneJang set to province:      " << InputProvince << " \n  So Whoever Wins The Round "<<InputProvince<<"Is Gonna Be In His Conquered Province List  "<<std::endl;
        flag = false ; 
    } else {
        std::cout << "Province not found. NeshaneJang not set." << std::endl;
    }
        
    }

}

void Game::initiateBattle() {
    if (currentBattle) {
        delete currentBattle;
    }

    currentBattle = new Battle(map.getProvinceByIndex(int(NeshaneJangProvince)), players, deck);

    currentBattle->startBattle();

    

    NeshaneJangSetter = currentBattle->endBattle();

    NeshaneSolhSetter = currentBattle->getNeshaneSolhSetter();


}

bool Game::checkForWinner() { 
    for (auto &player : players) {
        if (player.winnerDeterminer()) {
            winner = &player;
            return true;
        }
    }
    return false;
}

void Game::endGame() {
    system("clear");
    std::cout << "\n\n\tPlayer " << winner->getName() << " has won the game!!";
}