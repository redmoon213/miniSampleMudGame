#include "MonsterFactory.h"
#include "Orc.h"
#include "Ghost.h"
#include "Bandit.h"
#include "LastBoss.h"
#include "Zombie.h"

std::unique_ptr<Monster> MonsterFactory::GenerateMonster(monsterType type)
{
        switch (type)
        {
        case monsterType::LASTBOSS :    return std::make_unique<LastBoss>();
        case monsterType::ORC:          return std::make_unique<Orc>();
        case monsterType::GHOST:        return std::make_unique<Ghost>();
        case monsterType::BANDIT:       return std::make_unique<Bandit>();
        //case monsterType::ZOMBIE:       return std::make_unique<Zombie>();
                
        default: return nullptr;
        }
}

/*
std::unique_ptr<Monster> MonsterFactory::GenerateMonster(MonsterDB db)
{
        switch (db.type)
        {
        case monsterType::LASTBOSS :    return std::make_unique<LastBoss>();
        case monsterType::ORC:          return std::make_unique<Orc>();
        case monsterType::GHOST:        return std::make_unique<Ghost>();
        case monsterType::BANDIT:       return std::make_unique<Bandit>();
               
                
        default: return nullptr;
        }
}
*/
