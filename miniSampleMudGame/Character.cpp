#include "Character.h"

Character::Character(std::string name, int str, int dex, int intel):
name(name), strength(str), dexterity(dex), intelligence(intel)
{
    attackDamage = str * 2;
    maxHp = str * 20;
    hp = maxHp;
    maxMp = intel * 10;
    mp = maxMp;
    isAlive = true;
}

void Character::AttackNormal()
{
    
}

void Character::AttackSkill()
{
    
}

void Character::TakeDamage(int damage)
{
    hp -= damage;
}
