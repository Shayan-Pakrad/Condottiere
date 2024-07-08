#include "Map.h"

// Constructor
    std::array<std::array<int, 14>, 14> Map::boarderingProvinces{{
        {0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},  // BELLA
        {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},  // CALINE
        {0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},  // ENNA
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},  // ATELA
        {1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},  // PLADACI
        {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},  // BORGE
        {0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},  // DIMASE
        {0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0},  // MORINA
        {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0},  // OLIVIA
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},  // ROLLO
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},  // TALMONE
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0},  // ARMENTO
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},  // LIA
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}   // ELINA

    }};
    std::array<Province, 14> Map::provinces = {{
    Province("BELLA"),
    Province("CALINE"),
    Province("ENNA"),
    Province("ATELA"),
    Province("PLADACI"),
    Province("BORGE"),
    Province("DIMASE"), 
    Province("MORINA"),
    Province("OLIVIA"),
    Province("ROLLO"),
    Province("TALMONE"),
    Province("ARMENTO"),
    Province("LIA"),
    Province("ELINA")
}};
Map::Map(){

};

void Map::provinceListPrinter(){
    for (int i = 0; i <provinces.size() ; i++)
    {
        std::cout << provinces[i].getName()<<" -- ";
    }
    std::cout <<"\n" ;
    
}


Province& Map::getProvinceByIndex(int index) {
    return provinces[index];
}
