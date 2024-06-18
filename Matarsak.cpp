#include "Matarsak.h"

Matarsak::Matarsak(): SpecialCard(0, "matarsak") {}

void Matarsak::applyEffect(Player &player) {

    if (player.getCombatCardsPlayed().empty()) {
        std::cout << "No combat cards have been played.\n";
        std::cin.get();
        return;
    }
    
    std::cout << "\nWhich Yellow card do you want to pick up (for example 3) : ";
    std::string selectedCard;
    std::cin >> selectedCard;

    bool isFounded = false;

    do {
        for (auto &card : player.getCombatCardsPlayed()) {
            if (selectedCard == card->getName()) {
                isFounded = true;
                player.retakeCombatCard(card);
            }
        }

        if (!isFounded) {
            std::cout << "Invalid card, choose another card : ";
            std::cin >> selectedCard;
        }
    } while (!isFounded);


}