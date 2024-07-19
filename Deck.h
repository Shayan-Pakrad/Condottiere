#ifndef DECK_H
#define DECK_H

#include <vector>
#include <memory>
#include <algorithm>
#include <random>

#include "CombatCard.h"
#include "SpecialCard.h"
#include "Matarsak.h"
#include "Bahar.h"
#include "ShahDokht.h"
#include "TablZan.h"
#include "Zemestan.h"
#include "RishSefid.h"

#include "Card.h"
#include "Player.h"


class Battle;

class Deck {
    public:
    Deck();

    void shuffleCards();
    void deal(Player &player);

    private:
    std::vector<std::shared_ptr<Card>> gameCards;
};

#endif // DECK_H