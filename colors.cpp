#include "colors.hpp"

using namespace std;

const SDL_Color darkGrey = { 26, 31, 40, 255 };
const SDL_Color orange = { 255, 145, 12, 255 };
const SDL_Color blue = { 0, 119, 211, 255 };
const SDL_Color cyan = { 1, 237, 251, 255 };
const SDL_Color yellow = { 254, 251, 52, 255 };
const SDL_Color green = { 83, 218, 63, 255 };
const SDL_Color purple = { 177, 18, 255, 255 };
const SDL_Color red = { 234, 20, 28, 255 };
const SDL_Color lightBlue = { 59, 85, 162, 255 };
const SDL_Color darkBlue = { 44, 44, 127, 255 };

vector<SDL_Color> GetCellColors()
{
    return { darkGrey, orange, blue, cyan, yellow, green, purple, red };
}