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
    float baseCooltime;
    
public:
    
    
    std::string GetName() const {return name;}
    std::string GetSkillText() const {return skillText;}
    bool IsReady() const ;
    
};
