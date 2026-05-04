#include "Hideout.h"
#include <iostream>
#include <windows.h>

#include "GameManager.h"
#include "Maps.h"

Hideout::Hideout(Player& playerInput):player(playerInput){}

Hideout::~Hideout()
{
    
}

void Hideout::HideoutMenu()
{
    int input=0;
    auto& instance = GameManager::getGameManager();
    
    system("cls");
    std::cout<<"====================================================\n";
    std::cout<<"1_캐릭터\n";
    std::cout<<"2_지도장치\n";
    std::cout<<"3_상인\n";
    std::cout<<"4_게임종료\n";
    std::cout<<"====================================================\n";
    
    std::cin>>input;
    
    switch (input)
    {
    case 1: 
        CharacterStatus(); break;
    case 2:
        MapDevice(); break;
    case 3:
        Merchant(); break;
    case 4: 
        instance.ExitGame(); break;
    default: 
        break;
        
    }
}

void Hideout::MapDevice()
{
    //Maps maps;
    std::cout<<"[맵에 진입합니다...]\n";
    
}

void Hideout::Merchant()
{
    
}

void Hideout::CraftingBench()
{
    
}

void Hideout::CharacterStatus()
{
    
    int input = 0;
    system("cls");
    std::cout<< "=============================================================\n";
    std::cout<< "<플레이어>\n";
    
    std::cout << "[체력] : " << player.GetMaxHp() << std::endl ;
    std::cout << "[마나] : " << player.GetMaxMP() << std::endl ;
    
    std::cout << "[공격력]  : " << player.GetAttackDamage() << std::endl ;
    std::cout << "[방어력]  : " << player.GetDefense() << std::endl;
    
    std::cout << "[힘]   : " << player.GetStrength() << std::endl;
    std::cout << "[민첩]  : " << player.GetDexterity() << std::endl;
    std::cout << "[지능]  : " << player.GetIntelligence() << std::endl;
    
    std::cout<< "=============================================================\n";
    std::cout<< "<착용중인 장비>\n";
    
    int i = 0;
    for (auto it : player.GetEquipment())
    {
        switch (static_cast<ItemType>(i))
        {
        case ItemType::Weapon :
                std::cout<<"[무기] : "; break;
        case ItemType::Armor:
            std::cout<<"[갑옷] : "; break;
        case ItemType::Helmet:
            std::cout<<"[투구] : "; break;
        case ItemType::Boots:
            std::cout<<"[신발] : "; break;
        default:
            break;
        }
        if (it == nullptr)
        {
            std::cout <<"빈 슬롯\n";
        }
        else
        {
            std::cout<< it->GetName() << "\n";
        }
        
        i++;
    }
    
    std::cin >> input;
    
    switch (input)
    {
    case 4: return;
    }
    
    return;
}
