#include "Monster.h"


Monster::Monster(std::string newName, int str, int dex, int intel, int exp, int itemReward)
    :Character(newName, str, dex, intel), expReward(exp), itemReward(itemReward)
{
    
}

Monster::~Monster(){}


