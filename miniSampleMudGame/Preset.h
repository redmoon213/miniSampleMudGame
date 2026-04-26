#pragma once
#include <string>

class Preset
{
private:
    int presetNumber;
    std::string roomName;
    std::string monsterName;
    
public:
    Preset(int presetNumber, std::string roomName, std::string monsterName = "");
    ~Preset();
    
    int GetPresetNumber(){return presetNumber;}
    std::string GetRoomName(){return roomName;}
    std::string GetMonsterName(){return monsterName;}
    
};
