#include "SkillDB.h"


std::unordered_map<std::string, SkillDB>SkillDB:: CreateSkillDB()
{
    std::unordered_map<std::string, SkillDB> db;
    
    db["강타"] = {"강타", {{EffectType::SingleTarget,-1},{EffectType::Damage, 70}, {EffectType::Active,-1}}, 5};
    db["회전베기"] = {"회전베기", {{EffectType::MultiTarget,-1},{EffectType::Damage, 50}, {EffectType::Active,-1}}, 10};
    db["응급처치"] = {"응급처치", {{EffectType::SingleTarget, -1}, {EffectType::Heal, 20}, {EffectType::Active, -1}}, 7};
    db["흡혈의강타"] ={"흡혈의강타", {{EffectType::SingleTarget,-1},{EffectType::Damage, 20}, {EffectType::Heal, 20}, {EffectType::Active, -1}}, 7};
    
    return db;
}