#include "Maps.h"
#include <iomanip>
#include "MonsterFactory.h"
#include <windows.h>


Maps::Maps(Player& playerInput, Preset& presetInput, bool isclear)
:player(playerInput),presets(presetInput), clearCheck(isclear)
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
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::vector<std::unique_ptr<Monster>> monsters;
    
    //set monster numb, get preset, 1~3
    
    srand(time(NULL));
    int monsterNumber =0;
    int monsterNumberRoll = rand()%100;
    
    if (monsterNumberRoll <60){monsterNumber = 1;}
    
    else if (monsterNumberRoll<90){monsterNumber = 2;}
    
    else{monsterNumber = 3;}
    
    
    //monster generate
    
    for (int i = 0; i<monsterNumber; i++)
    {
        monsterType mType = static_cast<monsterType>(rand()%static_cast<int>(monsterType::LASTBOSS));
      
        monsters.push_back(MonsterFactory::GenerateMonster(mType));
        //preset, choose monster 
        
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    
    while (player.IsAlive() && monsters.size() !=0 )
    {
        system("cls");
        Display(monsters,player);
        
        
        int target = rand()%monsters.size();
       
        //player skill check
        if (player.CheckSkillCooldown())
        {
            //monsters[target]->TakeDamage(player.ActivateSkill());
            player.ActivateSkill(monsters);
            
            Sleep(500);
        }
        
        
        //log
        
        monsters[target]->TakeDamage(player.AttackNormal());
        std::cout<< player.GetName() << "가 " << monsters[target]->GetName() << "에게 " 
                 << player.GetAttackDamage() <<"만큼의 피해를 입혔습니다! \n";
        
        //Sleep(700);
        
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
               // Sleep(700);
            }
        }
          
        else
        {
            //if (roomIndex == rooms.size()-1);
            //victory
            //loot
            //exp
        }
        Sleep(700);
        
        //log
        //Sleep(700);
        
        player.Cooling();
    }
    
}

void Maps::EnterNextRoom()
{
    //currentRoom = *rooms[roomIndex];
    if (roomIndex == rooms.size()-1)
    {
        clearCheck = true;
        return;
    }
        else
        roomIndex++;
}

void Maps::Display(std::vector<std::unique_ptr<Monster>>& monster, Player& player) 
{
    std::cout << "=============================================================\n";
    for (const auto& test : monster)
    {
       DrawGauge(test->GetName(), test->GetHp(), test->GetMaxHp(), 20);
    }
    std::cout << "=============================================================\n";    
    DrawGauge(player.GetName(), player.GetHp(), player.GetMaxHp(), 20);
    
    std::cout << "-------------------------------------------------------------\n";
    for (auto& it : player.GetSkillList())
    {
        std::cout<< it.GetName() << "(" << it.GetCurrentCooltime() << ")\n";
    }
    std::cout << "=============================================================\n"; 
}


void Maps::MapOpen()
{
    
    
    
}

void Maps::DrawGauge(std::string label, int current, int max, int barlength)
{
    const int BAR_LENGTH = barlength; // 체력바의 총 길이 (칸 수)
    
    // 백분율 계산 (0으로 나누기 방지)
    float percentage = (max > 0) ? (float)current / max : 0;
    if (percentage < 0) percentage = 0;
    
    int filledLength = (int)(percentage * BAR_LENGTH);

    // 이름 및 라벨 출력 (10칸 고정 폭)
    std::cout << std::left << std::setw(10) << label << " [";

    // 체력바 그리기
    for (int i = 0; i < BAR_LENGTH; ++i) {
        if (i < filledLength) std::cout << "■"; // 채워진 칸
        else std::cout << " ";                 // 빈 칸
    }

    // 수치 정보 출력 (현재/최대 및 퍼센트)
    std::cout << "] " << std::setw(3) << (int)(percentage * 100) << "% "
         << "(" << current << "/" << max << ")" << std::endl;
}
