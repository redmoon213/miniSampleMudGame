#pragma once

#include <memory>
#include <vector>
#include <string>

class Room
{
private:
    std::vector<Room*> previousRoom;
    std::vector<Room*> nextRoom;
    
    //std::unique_ptr<Room> nextRoomTemp;
    //std::unique_ptr<Room> previousRoomTemp;
    
    std::string name;
    int preset;
    int floor;  
    bool isCleared;
    
public:
    Room(std::string name, int floor, bool isCleared = false);
    ~Room();
    void Test();
    
    std::vector<Room*> GetPreviousRoom() const {return previousRoom;}
    std::vector<Room*> GetNextRoom() const {return nextRoom;}
    
    int GetFloor() const {return floor;}
    bool IsCleared() const {return isCleared;}
    std::string GetName() const {return name;}
    
    int GetPreset() const {return preset;}
    void SetPreviousRoom(std::vector<Room*>&);
    void SetNextRoom(std::vector<Room*>&);
    void SetPreset(int);
    void AddPreviousRoom(Room&);
    void SetName(std::string);
    void setCleared();
    void AddNextRoom(std::unique_ptr<Room>);
};
