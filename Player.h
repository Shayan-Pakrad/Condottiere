#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Province.h"

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

private:
    std::string name;
    int age;
    int totalScore = 0; // Initialize total score to 0
    std::string color;
    std::vector<Province> conqueredProvinces;
};

#endif // PLAYER_H