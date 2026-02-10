#pragma once
#include "blocks.cpp"
#include "grid.hpp" 
#include <SDL3/SDL.h>
#include <string>

using namespace std;

class Game {
public:
	Game();
	Grid grid;
	Block GetRandomBlock();
	vector<Block> GetAllBlocks();
	void Draw(SDL_Renderer* renderer);
	void HandleInput();
	void MoveBlockDown();
	bool gameOver;
	int score;
	bool scoreChanged;
private:
	bool IsBlockOutside();
	void MoveBlockLeft();
	void MoveBlockRight(); 
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
	vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
};