#pragma once
#include "Character.h"
#include<vector>
class Monster : public Character
{
    
protected:
    int expReward;
    int preset;
    std::vector<int> itemReward;
public:
    Monster(std::string name, int str, int dex, int intelligence, int expReward, int itemReward);
    virtual ~Monster();
    virtual int GetExpReward(){return expReward;}
    
};
