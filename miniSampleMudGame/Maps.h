#pragma once
#include "Monster.h"
#include "Player.h"
#include "Preset.h"
#include "Room.h"

class Maps
{
private:
    std::vector<std::unique_ptr<Room>> rooms;
    //Room* currentRoom;
    int roomIndex;
    Preset presets;
    
public:
    Maps(Preset&);
    void EnterNextRoom();
    void Battle(Player&);
    
    void Event();
    void MapOpen();
};
