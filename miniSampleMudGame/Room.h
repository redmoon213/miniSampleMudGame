#pragma once

#include <vector>
using namespace std;
class Room
{
private:
    vector<Room*> previousRoom;
    vector<Room*> nextRoom;
    int floor;
    bool isCleared;
public:
    Room(int floor, bool isCleared = false);
    ~Room();
    void Test();
    
    vector<Room*> GetPreviousRoom() const {return previousRoom;}
    vector<Room*> GetNextRoom() const {return nextRoom;}
    
    int GetFloor() const {return floor;}
    bool IsCleared() const {return isCleared;}
    
    void SetPreviousRoom(vector<Room*>&);
    void SetNextRoom(vector<Room*>&);
    
    void AddPreviousRoom(Room*);
};
