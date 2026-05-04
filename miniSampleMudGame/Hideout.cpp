#include "Hideout.h"

#include <iomanip>
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
    Preset pr(1,"2","3");
    Maps maps(player, pr);
    std::cout<<"[맵에 진입합니다...]\n";
    
    while (player.IsAlive()&&!maps.IsCleared())
    {
        maps.Battle(player);
        maps.EnterNextRoom();
    }
    
    if (player.IsAlive())
    {
        std::cout<<"[맵을 클리어하였습니다!]\n";
        std::cout << std::setfill('=') << std::setw(61)  << "" << std::endl;
        std::cout<<std::setfill(' ');
        
        system("pause");
        
    }
}

void Hideout::Merchant()
{
    
}

void Hideout::CraftingBench()
{
    
}

void Hideout::CharacterStatus()
{
    const int labelW = 10; // 항목 이름 칸
    const int valueW = 8;  // 수치 숫자 칸
    
    int input = 0;
    system("cls");
    std::cout<< "=============================================================\n";
    
    std::cout<< "<플레이어>\n";
    
    std::cout << std::left << std::setw(labelW) << "[체력]" << ": " 
              << std::right << std::setw(valueW) << player.GetMaxHp() << "    "
              << std::left << std::setw(labelW) << "[마나]" << ": " 
              << std::right << std::setw(valueW) << player.GetMaxMP() << std::endl;

    std::cout << std::left << std::setw(labelW) << "[공격력]" << ": " 
              << std::right << std::setw(valueW) << player.GetAttackDamage() << "    "
              << std::left << std::setw(labelW) << "[방어력]" << ": " 
              << std::right << std::setw(valueW) << player.GetDefense() << std::endl;

    std::cout << "-------------------------------------------------------------\n";

    // 3열 정렬 예시
    std::cout << "[힘]   : " << std::setw(5) << player.GetStrength() << "  "
              << "[민첩] : " << std::setw(5) << player.GetDexterity() << "  "
              << "[지능] : " << std::setw(5) << player.GetIntelligence() << std::endl;
    std::cout<< "=============================================================\n";
    std::cout<< "<착용중인 장비>\n";
    
    int i = 0;
    for (auto it : player.GetEquipment())
    {
        switch (static_cast<EquipSlot>(i))
        {
        case EquipSlot::Weapon:
                std::cout<<"[무기] : "; break;
        case EquipSlot::Helmet:
            std::cout<<"[투구] : "; break;
        case EquipSlot::Armor:
            std::cout<<"[갑옷] : "; break;
        case EquipSlot::Boots:
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
    std::cout<< "=============================================================\n";
    std::cout<< "1_[장비 변경하기]\n";
    std::cout<< "4_[되돌아가기]\n";
    
    
    std::cin >> input;
    
    switch (input)
    {
    case 1:
        
    case 4: return;
    }
    
    return;
}
