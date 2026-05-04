#include "Player.h"
#include "Monster.h"
#include "SkillDB.h"

Player::Player(std::string name, int str, int dex, int intel, int lv)
    :Character(name, str, dex, intel), level(lv), exp(0), maxExp(level*50)
{
    auto db = CreateSkillDB();
    skillList.push_back(UserSkills(db["강타"]));
    skillList.push_back(UserSkills(db["회전베기"]));
    equipment.fill(nullptr);
    equipment.at(static_cast<int>(EquipSlot::Weapon)) = new Item("나무검", ItemType::Weapon);
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
    for (int i = 0; i<2; i++)
    {
        std::cout <<">> 올릴 능력치를 입력하세요 | 남은 포인트 : " << 2-i <<"\n";
        std::cout <<"1.힘, 2.민첩 3.지능\n";
        std::cin>>input;
        switch (input)
        {
        case 1: strength ++;break;
        case 2: dexterity ++;break;
        case 3: intelligence ++;break;
        }
    }
    StatSetting();
    hp=maxHp;
}

int Player::AttackNormal()
{
    mp += intelligence; 
    if (mp>maxMp) mp = maxMp;
    
    return attackDamage;
}

void Player::Loot(std::vector<int> rewardItem)
{
    std::cout << "아이템을 획득하였습니다!\n";
    
    for (int item: rewardItem)
    {
        inventory[item]++;
        std::cout<< itemList[item] << "\n";
       
    }
}

void Player::Loot(int rewardItem)
{/*
    inventory[rewardItem]++;
    std::cout << "아이템을 획득하였습니다!\n";
    std::cout<< itemList[rewardItem] << "\n";*/
}

int Player::UsingItem()
{
    ////
   return 0;
}

void Player::Cooling()
{
    for (auto& it: skillList)
    {
        it.DecreaseCooltime();
    }
}

bool Player::CheckSkillCooldown()
{
    for (const auto& it : skillList)
    {
        if (it.IsReady()) return true;
    }
    
    return false;
}

int Player::ActivateSkill(std::vector<std::unique_ptr<Monster>>& monsters)
{
    std::vector<Monster> targetList;
    srand(time(NULL));
    
   for (auto& it : skillList)
   {
       if (it.IsReady())
       {
           it.SetCurrentCooltime(it.GetBaseCooltime());
           
           //싱글타겟 멀티타겟 체크
           for (auto& skills : it.GetSkillEffects())
           {
               if (skills.type==EffectType::SingleTarget)
               {
                   targetList.push_back(*monsters[rand()%monsters.size()]);
               }
               else if (skills.type==EffectType::MultiTarget)
               {
                   for (auto& i : monsters)
                   targetList.push_back(*i);
               }
           }
           
           //데미지 or 힐 체크
           for (auto& skills : it.GetSkillEffects())
           {
               if (skills.type==EffectType::Damage)
               {
                   for (auto& target: targetList)
                   {
                       target.TakeDamage(skills.value + dexterity * 1.5);
                       
                   }
               }
               
               if (skills.type==EffectType::Heal)
               {
                   Heal(skills.value);
               }
           }
           
           std::cout << "[" << it.GetName() << "] !! \n"; 
           break;
       }
   }
    return 0;
}
