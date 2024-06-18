#include "Player.h"
#include <iostream>

// Constructor
Player::Player(const std::string name, int age, const std::string color)
    : name(name), color(color), totalScore(0), hasPassed(false) {
    while (age <= 0) {
        if (age == 0) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        }
        std::cout << "Age is invalid" << std::endl
                  << "You cannot be UNBORN --- (Enter a positive number for age): ";
        std::cin >> age;
    }
    
    this->age = age;
    tablZanHazPlayed = false;
}

// Age getter function
int Player::getAge() const {
    return age;
}

// Name getter function
std::string Player::getName() const {
    return name;
}

// Color getter function
std::string Player::getColor() const {
    return color;
}

// Total score getter function
int Player::getTotalScore() const {
    return totalScore;
}

// Total score setter function
void Player::setTotalScore(int score) {
    totalScore = score;
}

// Add province to conqueredProvinces
void Player::addProvince(const Province& province) {
    conqueredProvinces.push_back(province);
}

// Return number of conqueredProvinces
int Player::getProvincesNumber() const {
    return conqueredProvinces.size();
}

std::vector<Province> Player::getConqueredProvinces() const {
    return conqueredProvinces;
}

std::vector<std::shared_ptr<Card>> Player::getCombatCardsPlayed() const {
    return combatCardsPlayed;
}

std::vector<std::shared_ptr<Card>> Player::getSpecialCardsPlayed() const {
    return specialCardsPlayed;
}

std::vector<std::shared_ptr<Card>> Player::getCardsInHand() const {
    return cardsInHand;
}

void Player::giveCard(std::shared_ptr<Card> &card) {
    cardsInHand.push_back(card);
}

std::shared_ptr<Card>& Player::playCard(std::string selectedCard) {
    bool isFounded = false;

    do {
        for (auto card = cardsInHand.begin(); card != cardsInHand.end(); ++card) {
            if ((*card)->getName() == selectedCard) {
                isFounded = true;
                if ((*card)->getType() == "combat") {
                    combatCardsPlayed.push_back(*card);
                    cardsInHand.erase(card);
                    return *card;
                }
                if ((*card)->getType() == "special") {
                    specialCardsPlayed.push_back(*card);
                    cardsInHand.erase(card);
                    return *card;
                }
            }
        }

        if (!isFounded) {
            std::cout << "Invalid card, choose another card : ";
            std::cin >> selectedCard;
        }

    } while(!isFounded);
}

void Player::retakeCombatCard(std::shared_ptr<Card> &card) {
    auto it = std::find(combatCardsPlayed.begin(), combatCardsPlayed.end(), card);
    if (it != combatCardsPlayed.end()) {
        combatCardsPlayed.erase(it);
    }
}

void Player::tablZanSwitch() {
    tablZanHazPlayed = true;
}

void Player::pass() {
    hasPassed = true;
}

bool Player::checkPass() {
    return hasPassed;
}