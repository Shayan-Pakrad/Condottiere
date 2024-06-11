#ifndef DECK_H
#define DECK_H

#include <vector>
#include <memory>
#include <algorithm>
#include <random>

#include "Card.h"
#include "Player.h"


class Deck {
    public:
    Deck();

    void shuffleCards();
    void deal(Player &player);

    private:
    std::vector<std::shared_ptr<Card>> gameCards;
};

#endif // DECK_H