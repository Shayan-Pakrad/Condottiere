#ifndef SHIRZAN_H
#define SHIRZAN_H
#include "SpecialCard.h"
class ShirZan: public SpecialCard{
public : 
ShirZan () ;
void applyEffect (Player &player)override ;
virtual void applyEffect (Battle &battle){};

private : 

};


#endif // SHIRZAN_H