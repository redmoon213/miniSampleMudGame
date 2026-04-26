#include "Event.h"
using namespace std;
Event::Event(Room& currentRoom):
currentRoom(&currentRoom){}

void Event::ChooseNextRoom()
{
    rm.ClearLog();
    cout<<">>진행할 방을 입력하세요.\n";
    int tempIndex = 1;
    int chooseInput = 0;
    if (currentRoom->GetFloor() != 4)
    {
        for (Room* temp : currentRoom->GetNextRoom())
        {
            string qwe = temp->GetName();
            cout << " " << tempIndex << "_ " << qwe << "\n";
            tempIndex++;
        }
    
        cin >> chooseInput;
        if (chooseInput >= 1 && chooseInput <= (int)currentRoom->GetNextRoom().size())
        {
            currentRoom = currentRoom->GetNextRoom()[chooseInput-1];
        }
        
        else
        {
            cout<<"잘못된 입력값입니다. 다시 입력해주세요. \n";
        }
    }
    
    else 
        cout << "<TEST :: ChooseRoom()> 이곳은 마지막 방입니다. \n";
}

void Event::EnterRoom()
{
    switch (currentRoom->GetPreset())
    {
    case 1: rm.DrawScene(sceneBoss); break;
    case 2: rm.DrawScene(sceneOrc);break;
    case 3: rm.DrawScene(sceneGhost);break;
    case 4: rm.DrawScene(sceneBandit); break;
    case 5: rm.DrawScene(sceneHealingSpring);break;
    case 6: rm.DrawScene(sceneVault);break;
    }
    rm.ClearLog();
    
}

void Event::Battle(Player& player, Monster* monster)
{
    int logCount =0;
    
    if (monster == nullptr)
        return;
    rm.ClearLog();
    
    int playerInput = 0;
    while (player.IsAlive() && monster->IsAlive())
    {
        rm.ClearLog();
        
        // 플레이어와 몬스터의 체력 상태, 그리고 행동 선택지를 한 줄로 합칩니다.
        string statusMsg = player.GetName() + "(" + to_string(player.GetHp()) + "|" +to_string(player.GetMp()) + ") vs " + 
                           monster->GetName() + "(" + to_string(monster->GetHp()) + ") | 1.공격 2.스킬 3.아이템";
                           
        cout << (statusMsg) <<"\n";
        
        cin>>playerInput;
        switch (playerInput)
        {
        case 1: monster->TakeDamage(player.AttackNormal()); break;
        case 2: //monster->TakeDamage(player.UsingSkills()); break;
        case 3: monster->TakeDamage(player.UsingItem()); break;
            
        }
        
        if (monster->IsAlive())
        {
            player.TakeDamage(monster->GetAttackDamage()); 
        }
        
    }
    
    if (!player.IsAlive())
    {
        rm.ClearLog();
        cout<<"Died...\n";
    }
    
    else
    {
        rm.ClearLog();
        currentRoom->setCleared();
        player.GainExp(monster->GetExpReward());
        
        player.Loot(monster->GetItemReward());
        system("pause");
    }
}

void Event::Special(Player& player)
{
    switch (currentRoom->GetPreset())
    {
    case 5: {
        int healAmount = player.GetMaxHp() / 5;
        if (healAmount + player.GetHp() > player.GetMaxHp())
            healAmount = player.GetMaxHp() - player.GetHp();
        cout << "회복의 샘이 당신을 치유합니다.\n";
        cout << "Hp가 " << healAmount << "회복됩니다.\n";
        player.SetHp(player.GetHp() + healAmount );
        
        system("pause");
        break;
    }
    case 6:
        {
            cout << "금고실입니다.쓸만한 아이템이 있을지 모릅니다.\n";
            srand(time(NULL));
            int itemCount = rand()%3+1;
            for (int i = 0; i<itemCount; i++ )
            {
                player.Loot(rand()%4+1);
            }
            system("pause");
            break;
        }
    }
}

int Event::GetPreset()
{
    return currentRoom->GetPreset();
}
