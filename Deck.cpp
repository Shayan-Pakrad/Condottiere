#include "Deck.h"

// Constructor
Deck::Deck() { // Creating cards and add them to the deck

    int i;
    // Creating CombatCards

    // combatCard with point 1 : 10
    for (i = 0; i < 10; i++) {
        gameCards.push_back(std::make_shared<CombatCard>(1));
    }
    // combatCard with point 2, 3, 4, 5, 6, 10 : 8
    for (i = 0; i < 8; i++) {
        gameCards.push_back(std::make_shared<CombatCard>(2));
    }
    for (i = 0; i < 8; i++) {
        gameCards.push_back(std::make_shared<CombatCard>(3));
    }
    for (i = 0; i < 8; i++) {
        gameCards.push_back(std::make_shared<CombatCard>(4));
    }
    for (i = 0; i < 8; i++) {
        gameCards.push_back(std::make_shared<CombatCard>(5));
    }
    for (i = 0; i < 8; i++) {
        gameCards.push_back(std::make_shared<CombatCard>(6));
    }
    for (i = 0; i < 8; i++) {
        gameCards.push_back(std::make_shared<CombatCard>(10));
    }

    // Creating SpecialCards

    // Matarsak : 16
    for (i = 0; i < 16; i++) {
        gameCards.push_back(std::make_shared<Matarsak>());
    }
    // TablZan : 6
    for (i = 0; i < 6; i++) {
        gameCards.push_back(std::make_shared<TablZan>());
    }
    // Bahar : 3
    for (i = 0; i < 3; i++) {
        gameCards.push_back(std::make_shared<Bahar>());
    }
    // Zemestan : 3
    for (i = 0; i < 3; i++) {
        gameCards.push_back(std::make_shared<Zemestan>());
    }
    // ShahDokht : 3
    for (i = 0; i < 3; i++) {
        gameCards.push_back(std::make_shared<ShahDokht>());
    }
    // RishSefid : 6
    for (i = 0; i < 6; i++) {
        gameCards.push_back(std::make_shared<RishSefid>());
    }

    shuffleCards();

}

void Deck::shuffleCards() {

    // generating a random number
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(gameCards.begin(), gameCards.end(), g);

}

void Deck::deal(Player &player) {
    player.emptyHand();
    for (int i = 0; i < 10 + player.getConqueredProvincesNumber(); i++) {
        player.giveCard(*gameCards.begin());
        gameCards.erase(gameCards.begin());
    }
}