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
    defense = 0;
}

Character::~Character(){}

bool Character::IsAlive()
{
    return hp>0;
}

void Character::AttackNormal()
{
    TakeDamage(attackDamage);
}

void Character::AttackSkill()
{
    
}

void Character::TakeDamage(int damage)
{
    hp -= damage;
    if (hp<0) hp = 0;
}

void Character::StatSetting()
{
    attackDamage = strength * 2;
    maxHp = strength * 20;
    maxMp = intelligence * 10;
}
