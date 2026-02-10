#include "text.hpp"
#include <string>
#include <sstream>

Score::Score(SDL_Renderer* renderer, TTF_Font* font) {
	destText = { 365, 15 };
	SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), strlen(scoreText.c_str()), textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
	SDL_GetTextureSize(textTexture, &destText.w, &destText.h);
	SDL_DestroySurface(scoreSurface);
}

void Score::Draw(SDL_Renderer* renderer) {
	SDL_RenderTexture(renderer, textTexture, NULL, &destText);
}

Next::Next(SDL_Renderer* renderer, TTF_Font* font) {
	destText = { 370, 175 };
	SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), strlen(scoreText.c_str()), textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
	SDL_GetTextureSize(textTexture, &destText.w, &destText.h);
	SDL_DestroySurface(scoreSurface);
}

void Next::Draw(SDL_Renderer* renderer) {
	SDL_RenderTexture(renderer, textTexture, NULL, &destText);
}

Gameover::Gameover(SDL_Renderer* renderer, TTF_Font* font) {
	destText = { 330, 450 };
	SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), strlen(scoreText.c_str()), textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
	SDL_GetTextureSize(textTexture, &destText.w, &destText.h);
	SDL_DestroySurface(scoreSurface);
}

void Gameover::Draw(SDL_Renderer* renderer) {
	SDL_RenderTexture(renderer, textTexture, NULL, &destText);
}

Restart::Restart(SDL_Renderer* renderer, TTF_Font* font) {
	destText = { 325, 500 };
	SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), strlen(scoreText.c_str()), textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
	SDL_GetTextureSize(textTexture, &destText.w, &destText.h);
	SDL_DestroySurface(scoreSurface);
}

void Restart::Draw(SDL_Renderer* renderer) {
	SDL_RenderTexture(renderer, textTexture, NULL, &destText);
}

UpdateScore::UpdateScore(SDL_Renderer* renderer, TTF_Font* font) {
	destText = { 320 + 80, 65};
	setlocale(LC_ALL, "");
	this->renderer = renderer;
	this->font = font;
	
}

void UpdateScore::Update() {
	char scoreText[10];
	sprintf_s(scoreText, "%d", game.score);
	SDL_Surface* scoreSurface = TTF_RenderText_Solid(
		font, scoreText, strlen(scoreText), textColor
	);
	if (!scoreSurface) {
		printf("Ошибка рендеринга текста: %s\n", SDL_GetError());
		return;
	}

	textTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
	if (!textTexture) {
		printf("Ошибка создания текстуры: %s\n", SDL_GetError());
		SDL_DestroySurface(scoreSurface);
		return;
	}

	SDL_DestroySurface(scoreSurface);
	SDL_GetTextureSize(textTexture, &destText.w, &destText.h);
}

void UpdateScore::Draw(SDL_Renderer* renderer) {
	SDL_RenderTexture(renderer, textTexture, NULL, &destText);
	
}


