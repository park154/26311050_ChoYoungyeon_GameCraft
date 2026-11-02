#include "Game.h"
#include <glc2d.h>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
    m_playerTex = g2_TextureLoad("resource/player.png", 0);

    if (m_playerTex == -1)
    {
        g2_SetWindowTitle("Image Load Failed");
    }
}

void Game::Update(float deltaTime)
{
    switch (m_state)
    {
    case GameState::Title:
        
        break;

    case GameState::Playing:
        
        break;

    case GameState::GameOver:
        
        break;

    case GameState::Clear:
        
        break;
    }
}

void Game::Render()
{
    switch (m_state)
    {
    case GameState::Title:
        
        break;

    case GameState::Playing:
    {
        
        if (m_playerTex != -1)
        {
            VEC2 position(350.0f, 500.0f);
            VEC2 scale(0.5f, 0.5f);

            g2_Draw2D(
                m_playerTex,
                nullptr,
                &position,
                &scale
            );
        }
        break;
    }

    case GameState::GameOver:
        
        break;

    case GameState::Clear:
        
        break;
    }
}

void Game::Release()
{
    
}