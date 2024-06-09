#include "CombatCard.h"
// Constructor
CombatCard::CombatCard(int point, int number): Card(point), cardNumber(number) {
    setType("combat");
}
