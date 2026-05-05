#include "Monster.h"


Monster::Monster(std::string newName, int str, int dex, int intel, int exp, std::vector<int> itemRewardN)
    :Character(newName, str, dex, intel), expReward(exp)
{
    for (int item : itemRewardN)
    itemReward.push_back(item);
}


Monster::Monster(MonsterDB db)
    :Character(db.name, db.str, db.dex, db.vit), expReward(50), itemReward(db.dropPool), dropGold(db.dropGold)
{
    
}

Monster::~Monster(){}


