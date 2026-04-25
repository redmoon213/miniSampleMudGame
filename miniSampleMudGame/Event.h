#pragma once
#include <iostream>
#include <vector>
#include "Room.h"
#include <string>

using namespace std;
class Event
{
    private:
        Room* currentRoom;
    
    public:
        Event(Room& currentRoom);
        void ChooseNextRoom();
        void EnterRoom();
};
