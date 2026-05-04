#pragma once
#include "Player.h"

class Hideout
{
private:
    Player& player;
public:
    Hideout(Player& player);
    ~Hideout();
    
    void HideoutMenu();
    void CraftingBench();
    void MapDevice();
    void Merchant();
    
    void CharacterStatus();
};
