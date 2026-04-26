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
    if (currentRoom->GetPreset() == 0)
    {
    }
    
    else if (currentRoom->GetPreset()  == 1)
    {
        
    }
    
    else if (1<currentRoom->GetPreset() && currentRoom->GetPreset() <5)
    {
       
    }
    
    else if (currentRoom->GetPreset() >= 5)
    {
       
    }
    
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
        string statusMsg = player.GetName() + "(" + to_string(player.GetHp()) + ") vs " + 
                           monster->GetName() + "(" + to_string(monster->GetHp()) + ") | 1.공격 2.스킬 3.아이템";
                           
        rm.DrawLog(statusMsg);
        
        cin>>playerInput;
        switch (playerInput)
        {
        case 1: monster->TakeDamage(player.GetAttackDamage()); break;
        case 2: //monster->TakeDamage(player.UsingSkills()); break;
        case 3: //using item
            ;
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
    }
}

int Event::GetPreset()
{
    return currentRoom->GetPreset();
}
