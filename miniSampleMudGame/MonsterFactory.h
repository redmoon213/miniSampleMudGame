#pragma once
#include <memory>

#include "Monster.h"

class MonsterFactory
{
public:
    MonsterFactory();
    
    static std::unique_ptr<Monster> GenerateMonster(monsterType);
   
};
