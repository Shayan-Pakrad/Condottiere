#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <limits>

#include "Province.h"
#include "Card.h"

class Card;

class Player {
public:
    // Constructor
    Player(const std::string name, int age, const std::string color);

    // Member functions
    int getAge() const;
    std::string getName() const;
    std::string getColor() const;
    int getTotalScore() const;
    void addProvince(const Province& province);
    std::vector<Province> getConqueredProvinces() const;
    int getConqueredProvincesNumber() const;
    std::vector<std::shared_ptr<Card>> getCombatCardsPlayed() const;
    std::vector<std::shared_ptr<Card>> getSpecialCardsPlayed() const;
    std::vector<std::shared_ptr<Card>> getCardsInHand() const;
    void giveCard(std::shared_ptr<Card> &card);
    std::shared_ptr<Card>* playCard(std::string selectedCard);
    void retakeCombatCard(std::shared_ptr<Card> &card);
    void tablZanSwitch();

    void pass();
    bool checkPass();
    void resetStatus();

    void emptyHand();

    void setPointsToOne(); // for when zemestan has played in the battle
    bool winnerDeterminer();
    


private:
    std::string name;
    int age;
    std::string color;
    std::vector<Province> conqueredProvinces;
    bool tablZanHazPlayed; // It sets true if the player play TablZan card
    std::vector<std::shared_ptr<Card>> combatCardsPlayed;
    std::vector<std::shared_ptr<Card>> specialCardsPlayed;

    std::vector<std::shared_ptr<Card>> cardsInHand;

    bool hasPassed;
};

#endif // PLAYER_H