#ifndef CARD_H
#define CARD_H

#include <array>
#include <string>

class Card {
public:
    // Member functions
    void setPoint(int p);
    int getPoint() const;

private:
    int point;
    std::array<std::string, 7> Mercenary;
    std::array<std::string, 7> Special;
};

#endif // CARD_H
