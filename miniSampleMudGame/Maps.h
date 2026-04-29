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
    bool clearCheck;
public:
    Maps(Preset&, bool check = false);
    void EnterNextRoom();
    void Battle(Player&);
    bool IsCleared(){return clearCheck;}
    
    void Display(std::vector<std::unique_ptr<Monster>>&, Player&) const;
    
    void Event();
    void MapOpen();
};
