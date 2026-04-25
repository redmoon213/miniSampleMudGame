#include "Room.h"

#include <iostream>


Room::Room(int floor, bool isCleared)
    :floor(floor), isCleared(isCleared)
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
    cout << "나의 다음 층 : " ;
    for (int i =0; i<nextRoom.size(); i++)
    {
        cout<< nextRoom[i]->GetFloor() << " ";
    }
    cout << "\n";
    cout << "나의 이전 층 : ";
    for (int i =0; i<previousRoom.size(); i++)
    {
        cout<< previousRoom[i]->GetFloor() << " ";
    }
    cout << "\n";
}
void Room::SetPreviousRoom(vector<Room*>& previous){previousRoom = previous;}
void Room::SetNextRoom(vector<Room*>& next){nextRoom = next;}

void Room::AddPreviousRoom(Room& previous){previousRoom.push_back(&previous);}
    

