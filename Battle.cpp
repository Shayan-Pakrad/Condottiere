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

    std::cout << "\n\n->-> Current Battle Is In : " << province.getName() << " <-<-\n\n";

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

        // Check Pass

        if (players[i].checkPass()) {
            std::cout << "  --> PASSED";
        }

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

void Battle::startBattle() {

    int passedPlayers = 0;
    while(passedPlayers != players.size()) {

        if (passedPlayers == players.size()) {
            return;
        }

        for(auto &player : players) { if (!player.checkPass()) {
            std::system("cls");
            // Print general information
            printInformation();
            // Print players cards
            std::cout << "Player " << player.getName() << " cards : ";
            for (auto &card : player.getCardsInHand()) {
                std::cout << card->getName() << "   ";
            }
            std::cout << std::endl;
            
            // Input chosen card and Apply its effect
            std::cout << "\nPlease Enter The Card You Want To Play : ";
            std::string inputCard;
            std::cin >> inputCard;

            std::shared_ptr<Card>* selectedCard = player.playCard(inputCard); // This returns nullptr when player choose to pass


            if(selectedCard != nullptr) {

                if ((*selectedCard)->getType() == "special") {
                    if ((*selectedCard)->getName() == "bahar" || (*selectedCard)->getName() == "zemestan") {
                        (*selectedCard)->applyEffect(*this);
                    }
                    else {
                        (*selectedCard)->applyEffect(player);
                    }
                }

            } else { passedPlayers++; }

        }}
    }
}