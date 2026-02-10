#pragma once 
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cstdio>
#include <string>
#include <vector>
#include "game.hpp"

using namespace std;

class Score {
public:
	Score(SDL_Renderer* renderer, TTF_Font* font);
	void Draw(SDL_Renderer* renderer);
private:
	TTF_Font* font; 
	SDL_Renderer* renderer;
	SDL_Texture* textTexture;
	SDL_FRect destText;
	string scoreText = "Score";
	SDL_Color textColor = {255, 255, 255, 255};
};

class Next {
public:
	Next(SDL_Renderer* renderer, TTF_Font* font);
	void Draw(SDL_Renderer* renderer);
private:
	TTF_Font* font;
	SDL_Renderer* renderer;
	SDL_Texture* textTexture;
	SDL_FRect destText;
	string scoreText = "Next";
	SDL_Color textColor = { 255, 255, 255, 255 };
};

class Gameover {
public:
	Gameover(SDL_Renderer* renderer, TTF_Font* font);
	void Draw(SDL_Renderer* renderer);
private:
	TTF_Font* font;
	SDL_Renderer* renderer;
	SDL_Texture* textTexture;
	SDL_FRect destText;
	string scoreText = "Game Over";
	SDL_Color textColor = { 255, 255, 255, 255 };
};

class Restart {
public:
	Restart(SDL_Renderer* renderer, TTF_Font* font);
	void Draw(SDL_Renderer* renderer);
private:
	TTF_Font* font;
	SDL_Renderer* renderer;
	SDL_Texture* textTexture;
	SDL_FRect destText;
	string scoreText = "Restart PRESS Space";
	SDL_Color textColor = { 255, 255, 255, 255 };
};

class UpdateScore {
public:
	UpdateScore(SDL_Renderer* renderer, TTF_Font* font);
	void Draw(SDL_Renderer* renderer);
	void Update();
private:
	int score;
	Game game;
	TTF_Font* font;
	SDL_Renderer* renderer;
	SDL_Texture* textTexture;
	SDL_FRect destText;
	string scoreText;
	SDL_Color textColor = { 255, 255, 255, 255 };
};