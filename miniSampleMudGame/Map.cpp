#include "Map.h"

#include "Orc.h"

Map::Map(Preset& presetInput):presets(presetInput)
{
    
    
}



void Map::Battle(Player& player)
{
    std::vector<std::unique_ptr<Monster>> monsters;
    
    //set monster numb, get preset, 1~3
    srand(time(NULL));
    int monsterNumber =0;
    int monsterNumberCheck = rand()%100;
    
    if (monsterNumberCheck <60) 
    {
        monsterNumber = 1;
    }
    
    else if (monsterNumberCheck<90)
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
        //preset, choose monster 
        if (rand()%4 == 0)
        monsters.push_back(std::make_unique<Orc>());
        //.....
    }
    
    
    while (player.IsAlive() && monsters.size() !=0 )
    {
        for (Monster* check : &monsters)
        {
            std::cout << check->GetName() << " :: " << check->GetHp()  << "\n";
        }
        
        int target = rand()%monsters.size();
        
        //player hp mp skill cooldonw.. 
        std::cout<< player.GetName() << " :: " << player.GetHp() << " | " << player.GetMp() << "\n";
        
        //player attack
        monsters[target]->TakeDamage(player.AttackNormal());
        
        
        //log
        std::cout<< player.GetName() << "가 " << monsters[target]->GetName() << "에게 " 
                 << player.GetAttackDamage() <<"만큼의 피해를 입혔습니다! ";
        
        //target monster isalive check  
        if (!monsters[target]->IsAlive())
        {
            std::cout << monsters[target]->GetName() << "을 처치했습니다!\n";
            monsters.erase(monsters.begin() + target);
        }
        
        //all monster isalive check
        if (!monsters.size()==0)
        {
            //monster attack
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
