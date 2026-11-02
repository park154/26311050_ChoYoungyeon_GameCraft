#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#include <vector>

enum class GameState
{
    Title,
    Playing,
    GameOver,
    Clear
};

class Game
{
private:
    GameState m_state = GameState::Title;

    Player m_player;
    std::vector<Enemy> m_enemies;
    std::vector<Bullet> m_bullets;

    int m_score = 0;
    int m_stage = 1;

   
    int m_playerTex = -1;

public:
    Game();
    ~Game();

    void Run();
    void Init();
    void Update(float deltaTime);
    void Render();
    void Release();
};