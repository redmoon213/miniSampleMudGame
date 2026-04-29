#include <iostream>
#include <cstdlib>
#include <vector>

#include "Room.h"
#include "Event.h"
#include "Maps.h"
#include "MonsterFactory.h"
#include "Preset.h"
#include "RanderManger.h"
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    //방 생성 및 초기화 
    vector<Preset> presets ={                        //각 방에 부여해줄 프리셋을 미리 지정
        Preset(0, "시작지점" ),
        Preset(1, "보스방", "보스"),
        Preset(2, "숲", "오크"),
        Preset(3, "묘지", "유령"),
        Preset(4, "빈민가", "도적"),
        Preset(5, "치유의샘"),
        Preset(6, "금고실")
    };
    
    
    vector<Room> rooms = {                          // 방에 층수를 부여해서 생성
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

    //시작방과 끝방에 프리셋과 이름 부여
    rooms[0].SetPreset(presets[0].GetPresetNumber());
    rooms[0].SetName(presets[0].GetRoomName());
    rooms[10].SetPreset(presets[1].GetPresetNumber());
    rooms[10].SetName(presets[1].GetRoomName());
    
    //나머지 방들에 프리셋 2~6번을 랜덤으로 지정해줌
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
        vector<Room*> nextRoomTemp;
        //연결될 방의 개수 : 1~3 개
        //일단 세개 넣고 nextRoomCount 개수만큼 랜덤인덱스를 제거
        
        if (roomIndex >= 0 && roomIndex < 7)
        {
            // 0 -> (1,2,3) -> (4,5,6) -> (7,8,9) -> 10 형태로 연결되야함
            for (int i =0; i<3; i++)
            {
                int temp = 3-(roomIndex+2)%3;
                nextRoomTemp.push_back(&rooms[roomIndex + temp+i]);
            }
            
            int nextRoomCount = rand()%3;  // 지울 방의 개수를 결정 0~2 : 셋중 하나
            int eraseIndex = 0;
            
            //switch문 안에 break;를 적지 않아서 2일때는 2번 지워지고 1일때는 1번만 지워지게 하였음
            switch (nextRoomCount)
            {
            case 2:
                eraseIndex = rand()%(nextRoomTemp.size()); 
                nextRoomTemp.erase(nextRoomTemp.begin() + eraseIndex);
            case 1:
                eraseIndex = rand()%(nextRoomTemp.size()); 
                nextRoomTemp.erase(nextRoomTemp.begin() + eraseIndex);
            default:
                break;
            }
            
            //다음방의 previousRoom 변수에 현재 위치한 방을 연결해줌.  
            roomCurrent.SetNextRoom(nextRoomTemp);
            for (int nextRoomIndex = 0; nextRoomIndex < nextRoomTemp.size(); nextRoomIndex++)
            {
                nextRoomTemp[nextRoomIndex]->AddPreviousRoom(roomCurrent);
                
            }
        }
        
        //7~9번방은 마지막 방인 10번방과 연결
        else
        {
            nextRoomTemp.push_back(&rooms[10]);
            roomCurrent.SetNextRoom(nextRoomTemp);
            rooms[10].AddPreviousRoom(roomCurrent);
        }
        
        nextRoomTemp.clear();
        roomIndex++;
    }
    
    //UI를 그리기위한 객체
    RenderManager ren;
    printf("\033[2;2H");
    ren.Initialize();
    
    
    Event event(rooms[0]);
    Player player("플레이어", 10,10,10);
    
    Maps mapTest(presets[0]);
    while (player.IsAlive() && !mapTest.IsCleared())
    {
        mapTest.Battle(player);
        if (player.IsAlive()){mapTest.EnterNextRoom();}
    }
    
    while (player.IsAlive() && !rooms[10].IsCleared())
    {
        event.EnterRoom(); // 방 입장   
        unique_ptr<Monster> monsterTemp = MonsterFactory::GenerateMonster(monsterType::ORC); // 방의 프리셋에 해당되는 몬스터 생성
        
        if (!event.IsCleard()) // 방이 클리어되지 않은 상태라면 프리셋을 체크해서 전투 or 이벤트 진입
        {
            if (event.GetPreset() >0 && event.GetPreset() <5);
            //event.Battle(player, monsterTemp );
            
            else if (event.GetPreset() < 7)
                event.Special(player);
        }
        
        if (!player.IsAlive() || rooms[10].IsCleared())break; 
        
        event.ChooseNextRoom(); // 다음 방 선택 후 이동
    }
    
    cout<<"종료!\n";
    return 0;
}
    