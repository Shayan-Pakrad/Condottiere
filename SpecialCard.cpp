#include "SpecialCard.h"

SpecialCard::SpecialCard(int point, std::string nameVal): Card(point), name(nameVal) {
    setType("special");
}