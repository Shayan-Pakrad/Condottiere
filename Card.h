#ifndef CARD_H
#define CARD_H

#include <array>
#include <string>

class Card {
public:
    // Constructor
    Card();
    // Member functions
    void setPoint(int p);
    int getPoint() const;

private:
    int point;
    std::array<std::string, 7> Special;
    std::array<std::string, 7> Combat;
};

#endif // CARD_H
