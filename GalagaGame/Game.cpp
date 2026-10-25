#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
    

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
        
        break;

    case GameState::GameOver:
        
        break;

    case GameState::Clear:
        
        break;
    }
}

void Game::Release()
{
    
}