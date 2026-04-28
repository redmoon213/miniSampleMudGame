#pragma once
#include <vector>
#include "Character.h"
#include <iostream>
#include "Item.h"
#include "Monster.h"

class Player : public Character
{
private:
    int level;
    int exp;
    int maxExp;
    std::vector<int> inventory;
    std::vector<std::string> itemList;
    
    std::vector<Item> newInventory;
public:
    Player(std::string name, int str, int dex, int intelligence, int level = 1);
    void GainExp(int exp);
    void LevelUp();
    //void UsingSkills();
    int AttackNormal() override ;
    int UsingItem();
    void NewUsingItem(Player&, Item&);
    void Loot(std::vector<int> rewardItem);
    void Loot(int rewardItem);
    void Loot(std::unique_ptr<Item>);
    
    
};
