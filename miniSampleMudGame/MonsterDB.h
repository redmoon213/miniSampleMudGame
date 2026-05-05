#pragma once
#include <string>
#include <unordered_map>
#include "MonsterType.h"


struct MonsterDB
{
public:
    std::string name;
    monsterType mtype;
    int str;
    int dex;
    int vit;
    
    std::vector<int>dropPool;
    int dropGold;
};

std::unordered_map<int, MonsterDB> CreateMonsterDB();