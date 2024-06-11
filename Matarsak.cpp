#include "Matarsak.h"

Matarsak::Matarsak(): SpecialCard(0, "matarsak") {}

void Matarsak::applyEffect(Player &player) {
    std::cout << "Which Yellow card do you want to pick up (for example 3) : ";
    std::string selectedCard;
    std::cin >> selectedCard;

    bool isFounded = false;
    do {
        for (CombatCard &card : player.getCombatCardsPlayed()) {
            if (selectedCard == card.getName()) {
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