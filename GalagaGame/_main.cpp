#include <glc2d.h>

#if defined(_DEBUG)
#if defined(_M_X64)
#pragma comment(lib, "glc2d_x64_debug.lib")
#elif defined(_M_IX86)
#pragma comment(lib, "glc2d_win32_debug.lib")
#endif
#else
#if defined(_M_X64)
#pragma comment(lib, "glc2d_x64_release.lib")
#elif defined(_M_IX86)
#pragma comment(lib, "glc2d_win32_release.lib")
#endif
#endif

#include "Game.h"

Game* g_game = nullptr;


int FrameMove()
{
    static auto lastTime = g2_TimeGetTime();

    auto currentTime = g2_TimeGetTime();

    float deltaTime =
        (currentTime - lastTime) / 1000.0f;

    lastTime = currentTime;

    if (g_game)
        g_game->Update(deltaTime);

    return 0;
}


int RenderFrame()
{
    if (g_game)
        g_game->Render();

    return 0;
}

int main()
{
    
    if (g2_InitSdk() < 0)
        return -1;

    
    Game game;
    g_game = &game;

    
    g2_SetFrameMove(FrameMove);
    g2_SetRender(RenderFrame);

    
    g2_SetClearColor(0xFF000020);

    
    if (g2_CreateWin(
        100, 100,
        800, 600,
        "Galaga",
        true, 1.0f) < 0)
    {
        g_game = nullptr;
        return -2;
    }

    
    game.Init();

    
    g2_Run();

    
    game.Release();
    g_game = nullptr;

    g2_DestroyWin();

    return 0;
}