#pragma once
#include <iostream>
#include <vector>
#include "Room.h"
#include <string>

#include "Player.h"
#include "Monster.h"

class Event
{
    private:
        Room* currentRoom;
    
    public:
        Event(Room&);
        void ChooseNextRoom();
        void EnterRoom();
        void Battle(Player& player, Monster* monster);
        bool IsCleard() const {return currentRoom->IsCleared();}
        int GetPreset();
};
