#pragma once
#include "Monster.h"
#include "Orc.h"
#include "Bandit.h"
#include "Ghost.h"

class MonsterFactory
{
public:
    MonsterFactory();
    
    static Monster* GenerateMonster(int);
   
};
