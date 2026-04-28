#include "Player.h"

Player::Player(std::string name, int str, int dex, int intel, int lv)
    :Character(name, str, dex, intel), level(lv), exp(0)
{
    maxExp = level * 50;
    itemList = {"", "좋은 몽둥이", "돌맹이", "영혼불꽃", "투척 나이프" };
    inventory = {0, 0, 1, 0, 0, 0};
    
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
        case 1: 
            strength ++; 
            std::cout<< "힘 " << strength-1 << "->" << strength << "\n"; 
            break;
        case 2: 
            dexterity ++;
            std::cout<< "민첩 " << dexterity-1 << "->" << dexterity << "\n"; 
            break;
        case 3: 
            intelligence++;
            std::cout<< "지능 " << intelligence-1 << "->" << intelligence << "\n"; 
            break;
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
{
    inventory[rewardItem]++;
    std::cout << "아이템을 획득하였습니다!\n";
    std::cout<< itemList[rewardItem] << "\n";
    
}

void Player::Loot(std::unique_ptr<Item> rewardItem)
{
    if (rewardItem != nullptr)
    {
        newInventory.push_back(*rewardItem);
        std::cout << "아이템을 획득하였습니다!\n";
        std::cout<< rewardItem->GetItemName() <<"\n";
    }
}



int Player::UsingItem()
{
    int outputCount = 1;
    int input =0;
    int damage = 0;
    std::vector<int> temp;
    std::cout << ">>사용할 아이템을 입력해주세요.\n";
    
    std::vector<std::vector<int>> itemcodeList;
    newInventory.push_back(*std::make_unique<Item>(1,"돌맹이", ItemType::CONSUMABLE));
    newInventory.push_back(*std::make_unique<Item>(2,"사과", ItemType::CONSUMABLE));
    newInventory.push_back(*std::make_unique<Item>(3,"투척단검", ItemType::CONSUMABLE));
    newInventory.push_back(*std::make_unique<Item>(2,"사과", ItemType::CONSUMABLE));
    newInventory.push_back(*std::make_unique<Item>(1,"돌맹이", ItemType::CONSUMABLE));
    int countConsumable =0;
    //for (int logIndex = 1; )
    for (int inventoryIndex = 0; inventoryIndex < newInventory.size(); inventoryIndex++)
    {
        if (newInventory[inventoryIndex].GetItemType() == ItemType::CONSUMABLE)
        {
            bool itemCount = false;
             for (int i =0; i< itemcodeList.size(); i++)
             {
                 if (newInventory[inventoryIndex].GetItemCode() == itemcodeList[i][0])
                 {
                     itemcodeList[i][1]++;
                     itemCount = true;
                 }
                 
             }
            if (itemCount == false)
            {
                itemcodeList.push_back({newInventory[inventoryIndex].GetItemCode(), 1});
            }
        }
    }
    
    for (int i =0; i<itemcodeList.size(); i++)
    {   std::string itemNameTemp; 
       for (int j =0; j<newInventory.size(); j++)
       {
           if (itemcodeList[i][0] == newInventory[j].GetItemCode())
           {
               itemNameTemp = newInventory[j].GetItemName();
               break;
           }
       }
        std::cout << i + 1 << "_ " << itemNameTemp << " X " << itemcodeList[i][1] << "\n"; 
    }
    ///숏소스 돌맹이 나무부메랑 천갑옷 나무부메랑 돌맹이 돌반지 투척단검 돌맹이 투척단검 투척단검 돌맹이 
    ///1_ 돌맹이 x 4
    ///2_ 나무부메랑 x 2
    ///3_ 투척단검 x 3
    ///
    
    
    
    
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
    
    NewUsingItem(*this, newInventory[0]);
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

void Player::NewUsingItem(Player& a, Item& b)
{
    b.UsingItem();
}
