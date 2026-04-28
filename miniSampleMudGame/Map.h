#pragma once
#include "Monster.h"
#include "Player.h"
#include "Preset.h"
#include "Room.h"

class Map
{
private:
    std::unique_ptr<Room> myRoom;
    Preset presets;
    
public:
    Map(Preset&);
    
    void Battle(Player&);
    void Event();
    void MapOpen();
};
