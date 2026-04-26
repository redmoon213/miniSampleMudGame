#pragma once
#include <vector>
#include "Character.h"
#include <iostream>

class Player : public Character
{
private:
    int level;
    int exp;
    int maxExp;
    std::vector<int> inventory;
    std::vector<std::string> itemList;
public:
    Player(std::string name, int str, int dex, int intelligence, int level = 1);
    void GainExp(int exp);
    void LevelUp();
    //void UsingSkills();
    int AttackNormal() override ;
    int UsingItem();
    void Loot(std::vector<int> rewardItem);
    void Loot(int rewardItem);
};
