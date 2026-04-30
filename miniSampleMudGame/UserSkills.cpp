#include "UserSkills.h"

UserSkills::UserSkills():name("Bash"),type(skillType::ACTIVE),baseCooltime(5), damage(5),currentCooltime(0)
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
