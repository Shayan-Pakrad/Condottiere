#ifndef CARD_H
#define CARD_H

#include <array>
#include <string>

class Card {
public:
    // Constructor
    Card(int point);
    // Member functions
    void setPoint(int p);
    int getPoint() const;
    void setType(std::string type);
    
private:

    std::string type;
    int point;
};

#endif // CARD_H
