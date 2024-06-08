#include "Player.h"

// Constructor
Player::Player(const std::string& name, int age, const std::string& color)
    : name(name), color(color), totalScore(0) {
    if (age > 0) {
        this->age = age;
    } else {
        while (true) {
            std::cout << "Age is invalid " << std::endl
                      << "You cannot be UNBORN --- (Enter a positive number for age): ";
            std::cin >> age;
            if (age > 0) {
                this->age = age;
                break;
            }
        }
    }
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