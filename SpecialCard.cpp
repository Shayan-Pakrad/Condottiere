#include "SpecialCard.h"

SpecialCard::SpecialCard(int point, std::string name): Card(point, name) {
    setType("special");
}
