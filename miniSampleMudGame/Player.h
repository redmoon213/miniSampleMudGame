#pragma once
#include <vector>
#include "Character.h"
#include <iostream>

#include "Inventory.h"
#include "UserSkills.h"

class Player : public Character
{
private:
    int level;
    int exp;
    int maxExp;
    std::vector<int> inventory;
    std::vector<std::string> itemList;
    std::vector<Inventory> newInventory;
    std::vector<UserSkills> skillList;
    
public:
    Player(std::string name, int str, int dex, int intelligence, int level = 1);
    void GainExp(int exp);
    void LevelUp();
    //void UsingSkills();
    int AttackNormal() override ;
    int UsingItem();
    void Cooling();
    bool CheckSkillCooldown();
    int ActivateSkill();
    
    std::vector<UserSkills> GetSkillList() const {return skillList;}
    
    
    void Loot(std::vector<int> rewardItem);
    void Loot(int rewardItem);
};
