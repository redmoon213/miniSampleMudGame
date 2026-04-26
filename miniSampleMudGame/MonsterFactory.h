#pragma once
#include "Monster.h"

class MonsterFactory
{
public:
    MonsterFactory();
    
    static Monster* GenerateMonster(int);
   
};
