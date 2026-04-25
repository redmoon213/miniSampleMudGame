#include "Event.h"

Event::Event(Room& currentRoom):
currentRoom(&currentRoom){}

void Event::ChooseNextRoom()
{
    cout << "진행할 방을 고르세요 \n";
    int tempIndex = 1;
    int chooseInput = 0;
    if (currentRoom->GetFloor() != 4)
    {
        for (Room* temp : currentRoom->GetNextRoom())
        {
            string qwe = temp->GetName();
            cout << tempIndex << "_ " << qwe << "\n";
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
    if (currentRoom->GetPreset() == 0)
    {
        cout<<"<TEST> 이곳은 시작지점입니다\n";
    }
    else if (0<currentRoom->GetPreset()<1)
    {
        cout<<"<Test> 이곳은 전투지역입니다.\n";
    }
    
    else if (currentRoom->GetPreset() >=1 && currentRoom->GetPreset()<5)
    {
        cout<<"<Test> 이곳은 이벤트지역입니다.\n";
    }
    
    else if (currentRoom->GetPreset()  == 5)
    {
        cout<<"<Test> 이곳은 마지막 보스방입니다.\n";
    }
}
