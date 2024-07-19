#include "Player.h"
#include <iostream>
#include "Map.h"
#include "Game.h"
// Constructor
Player::Player(const std::string name, int age, const std::string color)
    : name(name), color(color), hasPassed(false)
{
    while (age <= 0)
    {
        if (age == 0)
        {
            std::cin.clear();                                                   // Clear error flags
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
int Player::getAge() const
{
    return age;
}

// Name getter function
std::string Player::getName() const
{
    return name;
}

// Color getter function
std::string Player::getColor() const
{
    return color;
}

// Total score getter function
int Player::getTotalScore() const
{
    int overall = 0;
    for (auto combatCard = combatCardsPlayed.begin(); combatCard != combatCardsPlayed.end(); ++combatCard)
    {
        overall = overall + ((*combatCard)->getPoint());
    }
    for (auto specialCard = specialCardsPlayed.begin(); specialCard != specialCardsPlayed.end(); ++specialCard)
    {
        overall = overall + ((*specialCard)->getPoint());
    }

    if (tablZanHazPlayed) {
        overall *= 2;
    }
    return overall;
}

// Add province to conqueredProvinces
void Player::addProvince(const Province &province)
{
    conqueredProvinces.push_back(province);
}

std::vector<Province> Player::getConqueredProvinces() const
{
    return conqueredProvinces;
}
int Player::getConqueredProvincesNumber() const
{
    return conqueredProvinces.size();
}

std::vector<std::shared_ptr<Card>> Player::getCombatCardsPlayed() const
{
    return combatCardsPlayed;
}

std::vector<std::shared_ptr<Card>> Player::getSpecialCardsPlayed() const
{
    return specialCardsPlayed;
}

std::vector<std::shared_ptr<Card>> Player::getCardsInHand() const
{
    return cardsInHand;
}

void Player::giveCard(std::shared_ptr<Card> &card)
{
    cardsInHand.push_back(card);
}

std::shared_ptr<Card> *Player::playCard(std::string selectedCard)
{

    bool isFounded = false;

    do
    {

        if (selectedCard == "pass")
        {
            pass();
            break;
        }
        for (auto card = cardsInHand.begin(); card != cardsInHand.end(); ++card)
        {
            if ((*card)->getName() == selectedCard)
            {
                isFounded = true;
                if ((*card)->getType() == "combat")
                {
                    combatCardsPlayed.push_back(*card);
                    cardsInHand.erase(card);
                    return &combatCardsPlayed[0];
                }
                if ((*card)->getType() == "special")
                {
                    specialCardsPlayed.push_back(*card);
                    cardsInHand.erase(card);
                    return &specialCardsPlayed[0];
                }
            }
        }

        if (!isFounded)
        {
            std::cout << "Invalid card, choose another card : ";
            std::cin >> selectedCard;
        }

    } while (!isFounded);

    return nullptr;
}

void Player::retakeCombatCard(std::shared_ptr<Card> &card)
{
    auto it = std::find(combatCardsPlayed.begin(), combatCardsPlayed.end(), card);
    if (it != combatCardsPlayed.end())
    {
        cardsInHand.push_back(*it);
        combatCardsPlayed.erase(it);
    }
}

void Player::tablZanSwitch()
{
    tablZanHazPlayed = true;
}

void Player::pass()
{
    hasPassed = true;
}

bool Player::checkPass()
{
    return hasPassed;
}

void Player::resetStatus()
{
    hasPassed = false;
    tablZanHazPlayed = false;
    specialCardsPlayed.clear();
    specialCardsPlayed.shrink_to_fit();
    combatCardsPlayed.clear();
    combatCardsPlayed.shrink_to_fit();
}

void Player::emptyHand()
{
    cardsInHand.clear();
    cardsInHand.shrink_to_fit();
}

void Player::setPointsToOne()
{
    for (auto card = combatCardsPlayed.begin(); card != combatCardsPlayed.end(); ++card)
    {
        (*card)->setPoint(1);
    }
}

bool Player::winnerDeterminer()
{

    if (conqueredProvinces.size() < 3) {
        return false;
    }
    
    std::string provinceName1 = conqueredProvinces[0].getName();
    std::string provinceName2 = conqueredProvinces[1].getName();
    std::string provinceName3 = conqueredProvinces[2].getName();
    prov provinceEnum1 = provinceMap[provinceName1];
    prov provinceEnum2 = provinceMap[provinceName2];
    prov provinceEnum3 = provinceMap[provinceName3];
    
    // Check if the provinces are bordering(MAIN PART OF THE FUNCTION )

    if (conqueredProvinces.size() == 3)
    {
        if (Map::boarderingProvinces[provinceEnum1][provinceEnum2] == 1)
        {
            if (Map::boarderingProvinces[provinceEnum1][provinceEnum3] == 1)
            {
                if (Map::boarderingProvinces[provinceEnum3][provinceEnum2] == 1)
                {
                    return true;
                }
            }
        }
    }

    else if (conqueredProvinces.size() == 4)
    {

        std::string provinceName4 = conqueredProvinces[3].getName();
        prov provinceEnum4 = provinceMap[provinceName4];

        if (Map::boarderingProvinces[provinceEnum1][provinceEnum2] == 1)
        {
            if (Map::boarderingProvinces[provinceEnum1][provinceEnum3] == 1)
            {
                if (Map::boarderingProvinces[provinceEnum3][provinceEnum2] == 1)
                {
                    return true;
                }
            }
        }

        if (Map::boarderingProvinces[provinceEnum1][provinceEnum4] == 1)
        {
            if (Map::boarderingProvinces[provinceEnum2][provinceEnum4] == 1)
            {
                if (Map::boarderingProvinces[provinceEnum1][provinceEnum2] == 1)
                {
                    return true;
                }
            }
        }

        if (Map::boarderingProvinces[provinceEnum1][provinceEnum3] == 1)
        {
            if (Map::boarderingProvinces[provinceEnum4][provinceEnum3] == 1)
            {
                if (Map::boarderingProvinces[provinceEnum3][provinceEnum4] == 1)
                {
                    return true;
                }

            }
        }

        if (Map::boarderingProvinces[provinceEnum3][provinceEnum2] == 1)
        {
            if (Map::boarderingProvinces[provinceEnum4][provinceEnum3] == 1)
            {
                if (Map::boarderingProvinces[provinceEnum2][provinceEnum4] == 1)
                {
                    return true;
                }
            }
        }
    }
    else if (conqueredProvinces.size() == 5)
    {
        return true;
    }

    return false;

}