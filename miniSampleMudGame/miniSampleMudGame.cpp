#include <iostream>
#include <cstdlib>
#include <vector>

#include "Room.h"
using namespace std;



int main()
{
    int preset[10] = {NULL};
    vector<Room> rooms = {
        Room(0),
        Room(1),
        Room(1),
        Room(1),
        Room(2),
        Room(2),
        Room(2),
        Room(3),
        Room(3),
        Room(3),
        Room(4)
    };
    
    srand((unsigned int)time(NULL));    
    //방들을 서로 연결
    int curruntFloor = 0;
    
    //참조자 쓸지 포인터쓸지 생각좀 잘 해보기
    int roomIndex = 0;
    for (Room& roomCurrent : rooms)
    {
        //연결될 방의 개수 : 1~3 개
        int nextRoomCount = 0;
        vector<Room*> nextRoomTemp;
        //연결될 방을 선택해야함
        //일단 세개 넣고 nextRoomCount 개수만큼 랜덤인덱스를 제거하면 될듯?
        
        if (roomIndex >= 0 && roomIndex < 7)
        {
            for (int i =0; i<3; i++)
            {
                int temp = 3-(roomIndex+2)%3;
                nextRoomTemp.push_back(&rooms[roomIndex + temp+i]);
            }
            
            nextRoomCount = rand()%4 +1;
            int eraseIndex = 0;
            switch (nextRoomCount)
            {
                
            case 1:
                eraseIndex = rand()%(nextRoomTemp.size()); // 0~3
                nextRoomTemp.erase(nextRoomTemp.begin() + eraseIndex);
            case 2:
                eraseIndex = rand()%(nextRoomTemp.size()); // 0~2
                nextRoomTemp.erase(nextRoomTemp.begin() + eraseIndex);
            default:
                cout << "error ! \n";        
            }
            
            roomCurrent.SetNextRoom(nextRoomTemp);
            for (int nextRoomIndex = 0; nextRoomIndex < nextRoomTemp.size(); nextRoomIndex++)
            {
                nextRoomTemp[nextRoomIndex]->AddPreviousRoom(roomCurrent);
            }
            
        }
        
        else
        {
            nextRoomTemp.push_back(&rooms[10]);
            roomCurrent.SetNextRoom(nextRoomTemp);
        }
        /*roomIndex.SetNextRoom(nextRoomTemp);
        nextRoomTemp[0]->AddPreviousRoom(&roomIndex);
        nextRoomTemp.clear();*/
        nextRoomTemp.clear();
        roomIndex++;
    }
    
    for (Room& roomCurrent : rooms)
    {
        roomCurrent.Test();
    }
    
    
    std::cout << "Hello MiniSampleMudGame" << std::endl;
    return 0;
}
