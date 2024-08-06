#ifndef MAP_H
#define MAP_H


#include <iostream>
#include <array>
#include "Player.h"
#include "Province.h"

class Map {
public:
    // Constructor
    Map();

    void provinceListPrinter();  // to display a list of provinces for the player who supposed to set the province to fight on 

    Province& getProvinceByIndex(int index); // using enum in game class
    
    static std::array<std::array<int, 15>, 15> borderingProvinces;
private:
    static std::array<Province, 15> provinces;
};
#endif // MAP_H