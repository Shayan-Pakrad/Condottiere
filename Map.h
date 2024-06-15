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
    enum prov{
        BELLA = 0 ,
        CALINE=1 ,
        ENNA =2, 
        ATELA =3,
        PLADACI=4, 
        BORGE =5,
        DIMASE =6,
        MORINA =7,
        OLIVIA =8,
        ROLLO =9,
        TALMONE=10, 
        ARMENTO =11,
        LIA =12,
        ELINA=13  
        
    };

    bool provinceOwnerDesignative();

private:
    std::array<Province, 14> provinces;
    std::array<std::array<int, 14>, 14> boarderingProvinces;
};


#endif // MAP_H