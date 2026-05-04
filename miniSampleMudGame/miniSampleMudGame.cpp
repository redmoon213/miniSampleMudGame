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
    
    auto& game = GameManager::getGameManager();
    game.run();
    
    cout<<"종료!\n";
    return 0;
}
    