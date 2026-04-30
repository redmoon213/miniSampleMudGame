#pragma once
#include <string>

enum class skillType
{
    ACTIVE, PASSIVE
};

class UserSkills
{
    std::string name;
    skillType type;
    std::string skillText;
    int baseCooltime;
    int currentCooltime;
    int damage;
    
public:
    UserSkills();
    std::string GetName() const {return name;}
    std::string GetSkillText() const {return skillText;}
    bool IsReady() const;
    void DecreaseCooltime();
    int GetDamage() const{return damage;}
    int GetBaseCooltime() const{return baseCooltime;}
    int GetCurrentCooltime() const{return currentCooltime;}
    
    void SetCurrentCooltime(int cooltime){currentCooltime = cooltime;}
    
};
