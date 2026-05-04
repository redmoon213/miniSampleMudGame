#pragma once
#include <string>
#include <vector>


struct SkillDB;

enum class EffectType
{
    Active, Passive, SingleTarget, MultiTarget, Damage, Heal
};

struct SkillEffect
{
    EffectType type;
    int value;
};

class UserSkills
{
    std::string name;
    std::vector <SkillEffect> skillEffects;
    
    std::string skillText;
    int baseCooltime;
    int currentCooltime;
    
public:
    UserSkills(SkillDB&);
    std::string GetName() const {return name;}
    std::string GetSkillText() const {return skillText;}
    bool IsReady() const;
    void DecreaseCooltime();
    //int GetDamage() const{return damage;}
    int GetBaseCooltime() const{return baseCooltime;}
    int GetCurrentCooltime() const{return currentCooltime;}
    void SetCurrentCooltime(int cooltime){currentCooltime = cooltime;}
    
    std::vector<SkillEffect> GetSkillEffects() const {return skillEffects;}
    //void UseSkill(Player& player, Monster& monster);
    
};
