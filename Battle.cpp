#include "Battle.h"

// Constructor
Battle::Battle(Province &province, std::vector<Player> &players)
    : province(province), players(players), baharHasPlayed(false), 
    ZemestanHasPlayed(false) {}

// bahar and zemestan switch
void Battle::baharSwitch() {
    baharHasPlayed = true;
    ZemestanHasPlayed = false;
}

void Battle::zemestanSwitch() {
    ZemestanHasPlayed = true;
    baharHasPlayed = false;
}

void Battle::printInformation() {
    std::system("cls");

    std::cout << "\n\n->-> Current Battle Is In : " << province.getName() << "<-<-\n\n";

    // Players Played Cards

    std::cout << "Players Played Cards:" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].getName() << " : ";

        // Combat Cards Played

        std::cout << "Combat-Cards (   ";
        std::vector<std::shared_ptr<Card>> playedCards = players[i].getCombatCardsPlayed();
        for (int j = 0; j < playedCards.size(); j++) {
            std::cout << playedCards[j]->getName() << "   ";
        }
        std::cout << ")  ";

        // Special Cards Played

        std::cout << "Special-Cards (   ";
        playedCards = players[i].getSpecialCardsPlayed();
        for (int j = 0; j < playedCards.size(); j++) {
            std::cout << playedCards[j]->getName() << "   ";
        }
        std::cout << ")";

        std::cout << std::endl;
    }

    std::cout << "\n----------------------------------------------------------------------\n\n";

    // Players Conquered Provinces

    std::cout << "Players Conquered Provinces:" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].getName() << " : ";
        std::vector<Province> conqueredProvinces = players[i].getConqueredProvinces();
        for (int j = 0; j < conqueredProvinces.size(); j++) {
            std::cout << conqueredProvinces[j].getName() << "   ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n----------------------------------------------------------------------\n\n";

}