#include <iostream>
#include <cstdlib>
#include <vector>
#include "Room.h"
#include "Event.h"
#include "GameManager.h"
#include "Hideout.h"
#include "Maps.h"
#include "MonsterFactory.h"
#include "Preset.h"
#include "RanderManger.h"
using namespace std;

int main()
{
    //UI를 그리기위한 객체
    RenderManager ren;
    printf("\033[2;2H");
    ren.Initialize();
    
    
    Player player("플레이어", 10,10,10);

    auto& game = GameManager::getGameManager();
    game.run();
    
    cout<<"종료!\n";
    return 0;
}
    