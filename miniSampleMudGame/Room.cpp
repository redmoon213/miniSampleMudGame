#include "Room.h"
#include <iostream>


Room::Room(std::string name, int floor, bool isCleared)
    :name(name),floor(floor), isCleared(isCleared)
{
    previousRoom.clear();
    nextRoom.clear();
}

Room::~Room()
{
    previousRoom.clear();
    nextRoom.clear();
}

void Room::SetPreviousRoom(std::vector<Room*>& previous){previousRoom = previous;}
void Room::SetNextRoom(std::vector<Room*>& next){nextRoom = next;}

void Room::AddPreviousRoom(Room& previous){previousRoom.push_back(&previous);}

void Room::SetPreset(int newPreset)
{
    preset = newPreset;
}

void Room::SetName(std::string newName)
{
    name = newName;
}

void Room::setCleared()
{
    isCleared = true;
}
