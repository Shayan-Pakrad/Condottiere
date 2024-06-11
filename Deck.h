#ifndef DECK_H
#define DECK_H

#include <vector>
#include <memory>
#include "Card.h"


class Deck {
    public:
    Deck();

    private:
    std::vector<std::shared_ptr<Card>> gameCards;
};

#endif // DECK_H