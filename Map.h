#ifndef MAP_H
#define MAP_H


#include <iostream>
#include <array>
#include "Province.h"

class Map {
public:
    // Constructor
    Map();

    void provinceListPrinter() ;  
    // Enum for provinces

    bool provinceOwnerDesignative();

private:
    std::array<Province, 14> provinces;
    std::array<std::array<int, 14>, 14> boarderingProvinces;
};


#endif // MAP_H