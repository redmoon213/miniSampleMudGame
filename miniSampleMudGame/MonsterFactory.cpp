#include "MonsterFactory.h"
#include "Orc.h"
#include "Ghost.h"
#include "Bandit.h"
#include "LastBoss.h"

Monster* MonsterFactory::GenerateMonster(int preset)
{
        switch (preset){
        case 1: return new LastBoss();
        case 2: return new Orc();
        case 3: return new Ghost();
        case 4: return new Bandit();
        default: return nullptr;        
        }
        
}
