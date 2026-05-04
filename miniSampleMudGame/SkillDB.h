#pragma once
#include <string>
#include <unordered_map>

#include "UserSkills.h"

struct SkillDB
{
    std::string name;
    std::vector<SkillEffect> skillEffects;
    
    int baseCooltime;
    
    
    static std::unordered_map<std::string, SkillDB> CreateSkillDB();
    
};

