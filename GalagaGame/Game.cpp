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
    
    m_state = GameState::Title;

    
    m_titleFont = g2_FontCreate("Arial", 56);
    m_guideFont = g2_FontCreate("Arial", 26);

    m_backgroundTex = g2_TextureLoad("resource/background.png", 0);

    m_playerTex = g2_TextureLoad("resource/player.png", 0);

}

void Game::Update(float deltaTime)
{
    const KEYCODE* keys = g2_GetKeyboard();
    switch (m_state)
    {
    case GameState::Title:

        if (keys[VK_RETURN] == EINPUT_DOWN)
        {
            m_state = GameState::Playing;
        }
        break;
        
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
    {
        
        if (m_titleFont >= 0)
        {
            g2_FontDrawText(
                m_titleFont,
                { 290, 200 },
                0xFFFFFFFF,
                "GALAGA"
            );
        }

       
        if (m_guideFont >= 0)
        {
            g2_FontDrawText(
                m_guideFont,
                { 250, 340 },
                0xFFFFFF00,
                "PRESS ENTER TO START"
            );
        }

        break;
    }

    case GameState::Playing:
    {
        if (m_backgroundTex != -1)
        {
            VEC2 position(0.0f, 0.0f);
            VEC2 scale(1.0f, 1.0f);

            g2_Draw2D(
                m_backgroundTex,
                nullptr,
                &position,
                &scale
            );

        }
        
        if (m_playerTex != -1)
        {
            VEC2 position(250.0f, 350.0f);
            VEC2 scale(0.05f, 0.05f);

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
    if (m_backgroundTex != -1)
    {
        g2_TextureRelease(m_backgroundTex);
        m_backgroundTex = -1;
    }
    if (m_playerTex != -1)
    {
        g2_TextureRelease(m_playerTex);
        m_playerTex = -1;
    }
}