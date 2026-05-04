#include "GameManager.h"
#include "Maps.h"
#include "Hideout.h"
#include "Player.h"


GameManager::GameManager()
        :isRunning(true){}
GameManager::~GameManager() {}

class Hideout;
GameManager& GameManager::getGameManager()
{
        static GameManager instance;
        return instance;
}

void GameManager::run()
{
        Player player("플레이어", 20, 20, 20 );
        Hideout hideout(player);
        
        while (isRunning)
        {
                hideout.HideoutMenu();
        }
        
        return;
}
