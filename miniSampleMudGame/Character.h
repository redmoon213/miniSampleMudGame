#pragma once

#include <string>
#include <vector>
class Character
{
protected:
    std::string name;
    int strength, dexterity, intelligence;  //str-체력, 일반공격력 , dex-기술 쿨타임, 회피율, int-마나, 마나회복
    int attackDamage, hp, maxHp, mp, maxMp;
    //int criticalChance;
    
    float skillCooldown;
    float hpRegen;
    float mpRegen;
    
    int defense;    
    bool isAlive;
    
    std::vector <int> skills;
    
public:
    Character(std::string name, int str, int dex, int intelligence);
    virtual ~Character();
    
    std::string GetName(){return name;}
    int GetStrength(){return strength;}
    int GetDexterity(){return dexterity;}
    int GetIntelligence(){return intelligence;}
    int GetAttackDamage(){return attackDamage;}
    int GetHp(){return hp;}
    int GetMaxHp(){return maxHp;}
    int GetMp(){return mp;}
    int GetMaxMP(){return maxMp;}
    int GetDefense(){return defense;}
    bool IsAlive();
    
    void StatSetting();
    
    void SetHp(int amount);
    virtual int AttackNormal();
    virtual void AttackSkill(); 
    virtual void TakeDamage(int damage);
    
};
