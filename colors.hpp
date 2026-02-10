#pragma once
#include <SDL3/SDL.h>
#include <vector>

extern const SDL_Color darkGrey;
extern const SDL_Color green;
extern const SDL_Color red;
extern const SDL_Color orange;
extern const SDL_Color yellow;
extern const SDL_Color purple;
extern const SDL_Color cyan;
extern const SDL_Color blue;
extern const SDL_Color lightBlue;
extern const SDL_Color darkBlue;

std::vector<SDL_Color> GetCellColors();