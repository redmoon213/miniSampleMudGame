#pragma once
#include <memory>
#include "Monster.h"
#include "MonsterDB.h"

class MonsterFactory
{
public:
    static std::unique_ptr<Monster> GenerateMonster(monsterType);
    static std::unique_ptr<Monster> GenerateMonster(MonsterDB);
};
