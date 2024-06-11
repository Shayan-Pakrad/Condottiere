#include "CombatCard.h"
// Constructor
CombatCard::CombatCard(int point): Card(point, std::to_string(point)) {
    setType("combat");
}