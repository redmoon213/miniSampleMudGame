#include "UserSkills.h"


bool UserSkills::IsReady() const
{
    return baseCooltime == 0.0f;
}
