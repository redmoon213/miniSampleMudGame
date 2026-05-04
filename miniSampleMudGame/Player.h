#pragma once
#include <vector>
#include "Character.h"
#include <iostream>
#include <array>
#include "Inventory.h"
#include "Item.h"
#include "UserSkills.h"

enum class EquipSlot
{
    Helmet = 0,
    Armor,
    Weapon,
    Boots,
    Max
};
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
    std::array<Item*, static_cast<int>(EquipSlot::Max)> equipment;
    
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
    
    std::array<Item*,static_cast<int>(EquipSlot::Max)>GetEquipment(){return equipment;}
    void Loot(std::vector<int> rewardItem);
    void Loot(int rewardItem);
    
    void Equip();
};
