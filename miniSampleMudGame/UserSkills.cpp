#include "UserSkills.h"
#include "Player.h"
#include "Monster.h"
#include "SkillDB.h"

UserSkills::UserSkills(SkillDB& db)
    :name(db.name), skillEffects(db.skillEffects), baseCooltime(db.baseCooltime), currentCooltime(0)
{
    
}

bool UserSkills::IsReady() const
{
    return currentCooltime == 0;
}

void UserSkills::DecreaseCooltime()
{
    currentCooltime = std::max(currentCooltime-1, 0);
}
