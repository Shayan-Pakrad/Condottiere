#ifndef CARD_H
#define CARD_H

#include <array>
#include <string>

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
    
private:

    std::string type;
    int point;
    std::string name;
};

#endif // CARD_H
