#include "Matarsak.h"

Matarsak::Matarsak(): SpecialCard(0, "matarsak") {}

void Matarsak::applyEffect(Player &player) {

    if (player.getCombatCardsPlayed().empty()) {
        std::cout << "No COMBAT cards have been played.\n";
        std::cin.get();
        return;
    }
    player.setMatarsakCounter();
    std::cout << "\nWhich Combat card do you want to pick up ? \nYour played COMBAT cards are : \n";
        for (const auto &card : player.getCombatCardsPlayed()) {
        std::cout << "---> " << card->getName() << "\n";
    }
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
            std::cout <<"!!!You have not played " <<selectedCard<<"yet please choose another card : ";
            std::cin >> selectedCard;
        }
    } while (!isFounded);


}