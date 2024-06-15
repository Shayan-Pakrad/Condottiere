#ifndef MAP_H
#define MAP_H


#include <iostream>
#include <array>
#include "Province.h"

class Map {
public:
    // Constructor
    Map();

    void provinceListPrinter() ;  // to display a list of provinces for the player who supposed to set the province to fight on 
    // Enum for provinces (any input as province's string will be an integer index )

    bool provinceOwnerDesignative();

private:
    std::array<Province, 14> provinces;
    std::array<std::array<int, 14>, 14> boarderingProvinces;
};


#endif // MAP_H