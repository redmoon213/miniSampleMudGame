#pragma once
#include <vector>
#include "Character.h"
#include <iostream>
#include <array>
#include "Inventory.h"
#include "Item.h"
#include "UserSkills.h"

class Monster;
enum class EquipSlot
{
    Weapon = 0,
    Helmet,
    Armor,
    Boots,
    Max
};
class Player : public Character
{
private:
    int level;
    int exp;
    int maxExp;
    std::vector<std::string> itemList;
    std::vector<Item*> inventory;
    std::vector<UserSkills> skillList;
    std::array<Item*, static_cast<int>(EquipSlot::Max)> equipment;
    int gold = 2000;
    
public:
    Player(std::string name, int str, int dex, int intelligence, int level = 1);
    void GainExp(int exp);
    void LevelUp();
    //void UsingSkills();
    int AttackNormal() override ;
    
    int UsingItem();
    
    void Cooling();
    bool CheckSkillCooldown();
    int ActivateSkill(std::vector<std::unique_ptr<Monster>>&);
    
    std::vector<UserSkills> GetSkillList() const {return skillList;}
    std::array<Item*,static_cast<int>(EquipSlot::Max)>GetEquipment(){return equipment;}
    
    
    void Equip();
    
    
    void Loot(std::vector<int> rewardItem);
    void Loot(int gold);
    
    int GetGold(){return gold;}
    void SetGold(int amount){gold = amount;}
    
    //void Equip();
    
    void AddSkill(std::string);
    void RemoveSkill(std::string);
    
};
