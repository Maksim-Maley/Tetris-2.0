#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "game.hpp"
#include "text.hpp"


double lastUpdateTime = SDL_GetTicks() / 1000.0;

bool EventTriggered(double interval)
{
    double currentTime = SDL_GetTicks();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


SDL_Window* window;
SDL_Renderer* renderer;
TTF_Font* font;
Game game;
Score* g_score = nullptr;
Next* g_next = nullptr;
Gameover* g_over = nullptr;
Restart* g_restart = nullptr;
UpdateScore* g_upscore = nullptr;


SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    font = TTF_OpenFont("Font/monogram.ttf", 48);
    SDL_CreateWindowAndRenderer("Tetris", 500, 620, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL /* | SDL_WINDOW_BORDERLESS */, &window, &renderer);
    SDL_SetRenderLogicalPresentation(renderer, 500, 620, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    g_score = new Score(renderer, font);
    g_next = new Next(renderer, font);
    g_over = new Gameover(renderer, font);
    font = TTF_OpenFont("Font/monogram.ttf", 38);
    g_upscore = new UpdateScore(renderer, font);
    font = TTF_OpenFont("Font/monogram.ttf", 25);
    g_restart = new Restart(renderer, font);
    game.grid;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    SDL_SetRenderDrawColor(renderer, 44, 44, 127, 255);
    SDL_RenderClear(renderer);

    if (EventTriggered(500))
    {
        game.MoveBlockDown();
    }

    g_score->Draw(renderer);
    g_next->Draw(renderer);

    SDL_FRect scoreRect = { 320, 55, 170, 60 };
    SDL_SetRenderDrawColor(renderer, 59, 85, 162, 255);
    SDL_RenderFillRect(renderer, &scoreRect);

    if (game.scoreChanged) {
        g_upscore->Update(); // Пересоздаём текстуру с новым счётом
        game.scoreChanged = false; // Сброс флага
    }

    g_upscore->Draw(renderer);

    SDL_FRect nextRect = { 320, 215, 170, 180 };
    SDL_SetRenderDrawColor(renderer, 59, 85, 162, 255);
    SDL_RenderFillRect(renderer, &nextRect);

    game.Draw(renderer);

    if (game.gameOver)
    {
        g_over->Draw(renderer);
        g_restart->Draw(renderer);
    }

    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    
    game.HandleInput();
        
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    SDL_DestroyRenderer(renderer);  
    SDL_DestroyWindow(window);      
    SDL_Quit();                     
}
