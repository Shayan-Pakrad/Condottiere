#include "Game.h"

// Constructor
Game::Game() {
    startGame();
}

// Start the game by initializing and sorting players
void Game::startGame() {
    initPlayers();
    sortPlayers();
    
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
        players.push_back(player);
    }
}

// Add player to the players list
void Game::addPlayer(const Player& player) {
    players.push_back(player);
}

// Sort players vector based on their age
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
}


void Game::showCards() {
    int numberOfPlayers = players.size();
    for (int i = 0; i < numberOfPlayers; i++) {
        std::system("cls");

        std::cout << "I want to show " << players[i].getName() << "'s cards";
        std::cout << "Press ENTER to continue!";

        std::cin.get();
        std::system("cls");

        deck.deal(players[i]);

        std::vector<std::shared_ptr<Card>> playerCards = players[i].getCardsInHand();

        std::cout << "Here is " << players[i].getName() << "'s cards :" << std::endl << std::endl;

        for(int j = 0; j < playerCards.size(); j++) {
            std::cout << playerCards[i]->getName() << std::endl;
        }

        std::cout << std::endl << "press ENTER to continue!";
        std::cin.get();

    }
}