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
    
    std::string GetName() const {return name;}
    int GetStrength() const {return strength;}
    int GetDexterity() const {return dexterity;}
    int GetIntelligence() const {return intelligence;}
    int GetAttackDamage() const {return attackDamage;}
    int GetHp() const {return hp;}
    int GetMaxHp() const {return maxHp;}
    int GetMp() const {return mp;}
    int GetMaxMP() const {return maxMp;}
    int GetDefense() const {return defense;}
    bool IsAlive() const;
    
    void StatSetting();
    
    void SetHp(int amount);
    virtual int AttackNormal();
    virtual void AttackSkill(); 
    virtual void TakeDamage(int damage);
    
};
