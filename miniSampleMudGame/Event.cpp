#include "Event.h"

Event::Event(Room& currentRoom):
currentRoom(&currentRoom){}

void Event::ChooseNextRoom()
{
    cout << "진행할 방을 고르세요 \n";
    int tempIndex = 1;
    int chooseInput = 0;
    
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
}
