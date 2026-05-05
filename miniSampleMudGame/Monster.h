#pragma once
#include"Character.h"
#include<vector>
#include "MonsterDB.h"

class Monster : public Character
{
    
protected:
    int expReward;
    int preset;
    std::vector<int> itemReward;
    int dropGold;
public:
    Monster(MonsterDB);
    Monster(std::string name, int str, int dex, int intelligence, int expReward, std::vector<int> itemReward);
    virtual ~Monster();
    virtual int GetExpReward(){return expReward;}
    virtual std::vector<int> GetItemReward(){return itemReward;}
    virtual int GetDropGold(){return dropGold;}

    

};
