#include "Maps.h"

#include "MonsterFactory.h"
#include "Orc.h"

Maps::Maps(Preset& presetInput):presets(presetInput)
{
    rooms.push_back(std::make_unique<Room>("시작지점", 0, false));
    
    for (int i =1; i<presetInput.GetMapSize()-1; i++)
    {
        rooms.push_back(std::make_unique<Room>(std::to_string(i)+"번방", i, false));
    }
    rooms.push_back(std::make_unique<Room>("보스방", 1, false));
    
}



void Maps::Battle(Player& player)
{
    std::vector<std::unique_ptr<Monster>> monsters;
    
    //set monster numb, get preset, 1~3
    srand(time(NULL));
    int monsterNumber =0;
    int monsterNumberRoll = rand()%100;
    
    if (monsterNumberRoll <60) 
    {
        monsterNumber = 1;
    }
    
    else if (monsterNumberRoll<90)
    {
        monsterNumber = 2;
    }
    
    else
    {
        monsterNumber = 3;
    }
    
    
    //monster generate
    
    for (int i = 0; i<monsterNumber; i++)
    {
        
        monsterType mType = static_cast<monsterType>(rand()%static_cast<int>(monsterType::MAXCOUNT));
      
        monsters.push_back(MonsterFactory::GenerateMonster(mType));
        //preset, choose monster 
        
    }
    
    
    while (player.IsAlive() && monsters.size() !=0 )
    {
        system("cls");
        
        for (auto& check : monsters)
        {
            std::cout << check->GetName() << " :: " << check->GetHp()  << "\n\n\n\n";
        }
        
        int target = rand()%monsters.size();
        
        //player hp mp skill cooldonw.. 
        std::cout<< player.GetName() << " :: " << player.GetHp() << " | " << player.GetMp() << "\n";
        
        //player attack
        monsters[target]->TakeDamage(player.AttackNormal());
        
        
        //log
        std::cout<< player.GetName() << "가 " << monsters[target]->GetName() << "에게 " 
                 << player.GetAttackDamage() <<"만큼의 피해를 입혔습니다! \n";
        
        //target monster isalive check  
        if (!monsters[target]->IsAlive())
        {
            std::cout << monsters[target]->GetName() << "을 처치했습니다!\n";
            monsters.erase(monsters.begin() + target);
        }
        
        //all monster isalive check
        if (monsters.size()!=0)
        {
            //monster attack
            for (auto& check : monsters)
            {
                //player isalive check break
                //
                
                player.TakeDamage(check->AttackNormal());
                std::cout << check->GetName() <<"가 " << player.GetName() << "에게 " 
                    << check->GetAttackDamage() << "만큼의 피해를 입혔습니다!. \n";
                
            }
        }

        else
        {
            //victory
            //loot
            //exp
        }
        
        //log
        
        //system
    }
    
}

void Maps::EnterNextRoom()
{
    //currentRoom = *rooms[roomIndex];
    
}

