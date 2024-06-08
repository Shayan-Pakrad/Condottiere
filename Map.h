#ifndef MAP_H
#define MAP_H

#include <array>

class Map {
public:
    // Enum for provinces
    enum Province {
        BELLA = 0,
        CALINE,
        ENNA,
        ATELA,
        PLADACI,
        BORGE,
        DIMASE,
        MORINA,
        OLIVIA,
        ROLLO,
        TALMONE,
        ARMENTO,
        LIA,
        ELINA,
        PROVINCE_COUNT
    };

    // Constructor
    Map();

    // Member function
    bool provinceOwnerDesignative();

private:
    std::array<Province, 14> provinces;
    std::array<std::array<int, 14>, 14> boarderingProvinces;
};

#endif // MAP_H