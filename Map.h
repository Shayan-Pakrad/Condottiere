#ifndef MAP_H
#define MAP_H


#include <iostream>
#include <array>
#include "Province.h"

class Map {
public:
    // Constructor
    Map();

    void provinceListPrinter();  // to display a list of provinces for the player who supposed to set the province to fight on 
    bool provinceOwnerDesignative();

    Province& getProvinceByIndex(int index); // using enum in game class

private:
    std::array<Province, 14> provinces;
    std::array<std::array<int, 14>, 14> boarderingProvinces;
};


#endif // MAP_H