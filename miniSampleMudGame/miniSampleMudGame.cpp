#include <iostream>
#include <cstdlib>
#include <vector>

#include "Bandit.h"
#include "Room.h"
#include "Event.h"
#include "Ghost.h"
#include "MonsterFactory.h"
#include "Orc.h"
#include "Preset.h"
#include "RanderManger.h"
using namespace std;

int main()
{
    
    srand((unsigned int)time(NULL));    
    
    int preset[10] = {NULL};
    //방 생성 및 초기화 
    vector<Preset> presets ={
        Preset(0, "시작지점" ),
        Preset(1, "보스방", "보스"),
        Preset(2, "숲", "오크"),
        Preset(3, "묘지", "유령"),
        Preset(4, "빈민가", "도적"),
        Preset(5, "치유의샘"),
        Preset(6, "금고실")
    };
    
    
    vector<Room> rooms = {
        Room("0번방",0),
        Room("1번방",1),
        Room("2번방",1),
        Room("3번방",1),
        Room("4번방",2),
        Room("5번방",2),
        Room("6번방",2),
        Room("7번방",3),
        Room("8번방",3),
        Room("9번방",3),
        Room("10번방",4)
    };
    rooms[0].SetPreset(presets[0].GetPresetNumber());
    rooms[0].SetName(presets[0].GetRoomName());
    rooms[10].SetPreset(presets[1].GetPresetNumber());
    rooms[10].SetName(presets[1].GetRoomName());
    
    for (int i =1; i<rooms.size()-1; i++)
    {
        int presetNumber = presets[rand()%5+2].GetPresetNumber();
        rooms[i].SetPreset(presetNumber);
        rooms[i].SetName(presets[presetNumber].GetRoomName());
    }
    
    
    //방들을 서로 연결
    int roomIndex = 0;
    for (Room& roomCurrent : rooms)
    {
        //연결될 방의 개수 : 1~3 개
        
        vector<Room*> nextRoomTemp;
        //연결될 방을 선택
        //일단 세개 넣고 nextRoomCount 개수만큼 랜덤인덱스를 제거
        
        if (roomIndex >= 0 && roomIndex < 7)
        {
            for (int i =0; i<3; i++)
            {
                int temp = 3-(roomIndex+2)%3;
                nextRoomTemp.push_back(&rooms[roomIndex + temp+i]);
            }
            
            int nextRoomCount = rand()%3 +1;  // 지울 방의 개수를 선택 1~3 : 셋중 하나
            int eraseIndex = 0;
            switch (nextRoomCount)
            {
                
            case 1:
                eraseIndex = rand()%(nextRoomTemp.size()); // 삭제할 인덱스를 선택 : 0~2 : 셋중 하나
                nextRoomTemp.erase(nextRoomTemp.begin() + eraseIndex);
            case 2:
                eraseIndex = rand()%(nextRoomTemp.size()); // 0~1 : 둘중 하나 
                nextRoomTemp.erase(nextRoomTemp.begin() + eraseIndex);
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
            rooms[10].AddPreviousRoom(roomCurrent);
        }
        
        nextRoomTemp.clear();
        roomIndex++;
    }
    
    
    //cout << "\033[2J"; 
    //drawUI();
    
    //cout << "\033[20;3H"; 
    RenderManager ren;
    
   
    printf("\033[2;2H");
    ren.Initialize();
    
    
    Event event(rooms[0]);
    Player player("플레이어", 10,10,10);
   
    while (player.IsAlive() && rooms[10].IsCleared() != true)
    {
        event.EnterRoom();  
        Monster* monsterTemp = MonsterFactory::GenerateMonster(event.GetPreset());
        
        if (!event.IsCleard())
        event.Battle(player, monsterTemp );
        delete monsterTemp;
        
        if (!player.IsAlive())break;
        event.ChooseNextRoom();
    }
    cout<<"종료!\n";
    return 0;
}
    