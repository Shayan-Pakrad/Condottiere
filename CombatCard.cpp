#include "CombatCard.h"
// Constructor
CombatCard::CombatCard(int point, std::string cardNumber): Card(point, cardNumber) {
    setType("combat");
}