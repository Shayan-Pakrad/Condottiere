#ifndef MAP_H
#define MAP_H


#include <iostream>
#include <array>
#include "Province.h"

class Map {
public:
    void provinceListPrinter() ;  
    // Enum for provinces


    // Constructor
    Map();

    bool provinceOwnerDesignative();

private:
    std::array<Province, 14> provinces;
    std::array<std::array<int, 14>, 14> boarderingProvinces;
};


#endif // MAP_H