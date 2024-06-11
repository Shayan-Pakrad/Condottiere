#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Province.h"
#include "CombatCard.h"
#include "SpecialCard.h"
#include "Card.h"


class Player {
public:
    // Constructor
    Player(const std::string& name, int age, const std::string& color);

    // Member functions
    int getAge() const;
    std::string getName() const;
    std::string getColor() const;
    int getTotalScore() const;
    void setTotalScore(int score);
    void addProvince(const Province& province);
    int getProvincesNumber() const;
    std::vector<CombatCard> getCombatCardsPlayed() const;
    std::vector<std::shared_ptr<SpecialCard>> getSpecialCardsPlayed() const;
    std::vector<std::shared_ptr<Card>> getCardsInHand() const;
    void giveCard(auto &card);
    void playCard(std::string selectedCard);
    void retakeCombatCard(auto &card);
    void tablZanSwitch();


private:
    std::string name;
    int age;
    int totalScore = 0; // Initialize total score to 0
    std::string color;
    std::vector<Province> conqueredProvinces;
    bool tablZanHazPlayed; // It sets true if the player play TablZan card
    std::vector<CombatCard> combatCardsPlayed;
    std::vector<std::shared_ptr<SpecialCard>> specialCardsPlayed;

    std::vector<std::shared_ptr<Card>> cardsInHand;
};

#endif // PLAYER_H