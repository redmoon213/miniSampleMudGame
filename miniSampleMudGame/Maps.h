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
    Player& player;
public:
    Maps(Player& playerInput, Preset&, bool check = false);
    void EnterNextRoom();
    void Battle(Player&);
    bool IsCleared(){return clearCheck;}
    
    void Display(std::vector<std::unique_ptr<Monster>>&, Player&);
    
    void Event();
    void MapOpen();
    void DrawGauge(std::string, int current, int max, int barlength);
};
