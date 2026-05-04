#pragma once
class GameManager
{
private:
    GameManager();
    ~GameManager();
    
    bool isRunning;
    
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
public:
    
    static GameManager& getGameManager();
    
    
    void run();
    bool GetisRunning() const {return isRunning;}
    void ExitGame() {isRunning = false;}
};
