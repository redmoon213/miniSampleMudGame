#include "Player.h"

Player::Player(std::string name, int str, int dex, int intel, int lv)
    :Character(name, str, dex, intel), level(lv), exp(0)
{
    maxExp = level * 50;
}

void Player::GainExp(int expGain)
{
    exp += expGain;
    while (exp >= maxExp)
    {
        LevelUp();
        exp -= maxExp;
        maxExp = level * 50;
    }
}

void Player::LevelUp()
{
    level++;
    int input;
    std::cout <<"레벨업!" << level-1 << " -> " << level <<"\n";
    std::cout <<"올리실 능력치를 입력하세요 : 남은 포인트\n";
    std::cout <<"1.힘, 2.민첩 3.지능\n";
    std::cin>>input;
    switch (input)
    {
        case 1: strength ++;break;
        case 2: dexterity ++;break;
        case 3: intelligence ++;break;
    } 
    StatSetting();
    hp=maxHp;
}

void Player::UsingSkills()
{
}
