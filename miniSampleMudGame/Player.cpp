#include "Player.h"

Player::Player(std::string name, int str, int dex, int intel, int lv)
    :Character(name, str, dex, intel), level(lv), exp(0), maxExp(level*50)
{
    skillList.push_back(UserSkills());
    
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
        std::cout <<"\033[J";
        switch (input)
        {
        case 1: strength ++;break;
        case 2: dexterity ++;break;
        case 3: intelligence ++;break;
        }
        printf("\033[19;1H\033[J");
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
    int outputCount = 1;
    int itemCount = 0;
    int input =0;
    int damage = 0;
    std::vector<int> temp;
    std::cout << ">>사용할 아이템을 입력해주세요.\n";
    
    for (int inventoryIndex =0; inventoryIndex<inventory.size(); inventoryIndex++)
    {
        if (inventory[inventoryIndex]!=0)
        {
            std::cout << outputCount << ". " << itemList[inventoryIndex] << " X " << inventory[inventoryIndex] << "  |  ";
            switch (inventoryIndex)
            {
            case 2: 
                std::cout << "5의 데미지를 줍니다 \n";
                break;
            case 3:
                std::cout << "모든 mp를 소모하여 소모한 값에 비례한 큰 데미지를 줍니다. \n"; 
                break;
            case 4:
                std::cout << "민첩에 비례하는 데미지를 줍니다. \n";
                break;
                
            }
            
            
            temp.push_back(inventoryIndex);
            outputCount++;
        }
    }
    std::cin >> input;
    if (temp[input-1] != 0)
    {
        switch (temp[input-1])
        {
            case 2 : damage = 5; inventory[temp[input-1]]--; break;
            case 3 : damage = mp * 1; mp = 0; inventory[temp[input-1]]--; break;
            case 4 : damage = dexterity * 3; inventory[temp[input-1]]--; break;
            default: std::cout<<"올바르지 않은 입력입니다.\n"; break;
        }
    }
    
    return damage;
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

int Player::ActivateSkill()
{
   for (auto& it : skillList)
   {
       if (it.IsReady())
       {
           it.SetCurrentCooltime(it.GetBaseCooltime());
           return it.GetDamage();
       }
   }
    return 0;
}
