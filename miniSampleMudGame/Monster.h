#pragma once
#include "Character.h"
#include<vector>

enum class monsterType
{
    ORC, GHOST, BANDIT, 
    LASTBOSS
};
class Monster : public Character
{
    
protected:
    int expReward;
    int preset;
    std::vector<int> itemReward;
public:
    Monster(std::string name, int str, int dex, int intelligence, int expReward, std::vector<int> itemReward);
    virtual ~Monster();
    virtual int GetExpReward(){return expReward;}
    virtual std::vector<int> GetItemReward(){return itemReward;}
};
