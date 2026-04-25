#pragma once

#include <string>
#include <vector>
class Character
{
protected:
    std::string name;
    int strength, dexterity, intelligence;
    int attackDamage, hp, maxHp, mp, maxMp;
    //int criticalChance;
    int defense;    
    bool isAlive;
    
    std::vector <int> skills;
    
public:
    Character(std::string name, int str, int dex, int intelligence);
    ~Character();
    
    int GetStrength(){return strength;}
    int GetDexterity(){return dexterity;}
    int GetIntelligence(){return intelligence;}
    int GetAttackDamage(){return attackDamage;}
    int GetHp(){return hp;}
    int GetMaxHp(){return maxHp;}
    int GetMp(){return mp;}
    int GetMaxMP(){return maxMp;}
    int GetDefense(){return defense;}
    bool IsAlive(){return isAlive;}
    
    
    void AttackNormal();
    void AttackSkill();
    void TakeDamage(int damage);
    
};
