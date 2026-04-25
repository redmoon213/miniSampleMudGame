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

void Room::Test()
{
    std::cout << "나의 다음 층 : " ;
    for (int i =0; i<nextRoom.size(); i++)
    {
        std::cout<< nextRoom[i]->GetFloor() << " ";
    }
    std::cout << "\n";
    std::cout << "나의 이전 층 : ";
    for (int i =0; i<previousRoom.size(); i++)
    {
        std::cout<< previousRoom[i]->GetFloor() << " ";
    }
    std::cout << "\n";
}
void Room::SetPreviousRoom(std::vector<Room*>& previous){previousRoom = previous;}
void Room::SetNextRoom(std::vector<Room*>& next){nextRoom = next;}

void Room::AddPreviousRoom(Room& previous){previousRoom.push_back(&previous);}
    

