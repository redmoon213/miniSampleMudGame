#include "MonsterDB.h"


std::unordered_map<int, MonsterDB> CreateMonsterDB()
{
    std::unordered_map<int, MonsterDB> db;
    
    //db[1] = {"Golbin",monsterType::GOBLIN, 10,10,10};
    db[2] = {"Orc", monsterType::ORC, 10,10,10,{1, 21, 41}, 50};
    //db[3] = {"Goblin Archer", monsterType::GOBLINARCHER, 10, 10, 10};
    db[4] ={"Ghost", monsterType::GHOST, 10, 10, 10,{1, 21, 41}, 50};
    db[5] = {"Bandit", monsterType::BANDIT, 10, 10, 10, {1, 21, 41}, 50};
    
    db[101] = {"LastBoss", monsterType::LASTBOSS, 20, 20, 20, {3, 22, 42}, 150};
    //db[102] ={"LastBoss2", monsterType::LASTBOSS, 10, 10, 10};
    
    return db;
}