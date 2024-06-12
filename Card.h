#ifndef CARD_H
#define CARD_H

#include <array>
#include <string>

class Battle;
class Player;

class Card {
public:
    // Constructor
    Card(int point, std::string name);
    // Member functions
    void setPoint(int p);
    int getPoint() const;
    void setType(std::string type);
    std::string getType() const;
    std::string getName() const;
    virtual void applyEffect(Player &player) = 0;
    virtual void applyEffect(Battle &battle) = 0;
    
private:

    std::string type;
    int point;
    std::string name;
};

#endif // CARD_H
