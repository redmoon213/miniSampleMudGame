#include <iostream>
#include <cstdlib>
#include <vector>

#include "Room.h"
#include "Event.h"
using namespace std;

void resetCursor() {
    cout << "\033[H";
}

void drawUI() {
    // 설정값
    const int WIDTH = 60;   // UI 전체 가로 폭
    const int TOP_HEIGHT = 15; // 상단 영역 (배경/몬스터) 높이
    const int BOT_HEIGHT = 6;  // 하단 영역 (로그) 높이

    resetCursor();

    // 1. 상단 테두리
    cout << "┌";
    for(int i=0; i<WIDTH; i++) cout << "─";
    cout << "┐" << endl;

    // 2. 상단 영역 (배경 & 몬스터 공간)
    for(int i=0; i<TOP_HEIGHT; i++) {
        cout << "│";
        for(int j=0; j<WIDTH; j++) cout << " "; // 나중에 여기에 배경 출력
        cout << "│" << endl;
    }

    // 3. 중간 구분선
    cout << "├";
    for(int i=0; i<WIDTH; i++) cout << "─";
    cout << "┤" << endl;

    // 4. 하단 영역 (텍스트 로그 공간)
    for(int i=0; i<BOT_HEIGHT; i++) {
        cout << "│";
        for(int j=0; j<WIDTH; j++) cout << " "; // 나중에 여기에 로그 출력
        cout << "│" << endl;
    }

    // 5. 하단 테두리
    cout << "└";
    for(int i=0; i<WIDTH; i++) cout << "─";
    cout << "┘" << endl;
}

int main()
{
    
    srand((unsigned int)time(NULL));    
    
    int preset[10] = {NULL};
    //방의 프리셋 설정 
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
    rooms[0].SetPreset(0);
    for (int i =1; i<rooms.size()-1; i++)
    {
        rooms[i].SetPreset(rand()%4+1);
    }
    rooms[10].SetPreset(5);
    
    
    //방들을 서로 연결
    //참조자 쓸지 포인터쓸지 생각좀 잘 해보기
    int roomIndex = 0;
    for (Room& roomCurrent : rooms)
    {
        //연결될 방의 개수 : 1~3 개
        
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
    
    
    Event event(rooms[0]);
   
    //  while(!currentRoom.isCleared() || !player.isAlive())
    //  event.battleOrEvent(currentroom, player, monsters)
    //  event.reward(currentRoom, player)
    //  event.chooseRoom(currentRoom)
    //  
    cout << "\033[2J"; 
    drawUI();
    
    std::cout << "Hello MiniSampleMudGame" << std::endl;
    cout << "\033[20;3H"; 
    int temp;
    cin >> temp;
    return 0;
}
    