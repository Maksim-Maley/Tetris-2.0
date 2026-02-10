#pragma once
#include <vector>
#include <map>
#include "position.hpp"
#include "colors.hpp"
#include <SDL3/SDL.h>

using namespace std;

class Block {
public:
	Block();
	void Draw(SDL_Renderer* renderer, int offsetX, int offsetY);
	void Move(int rows, int columns);
	void Rotate();
	void UndoRotation();
	vector<Position> GetCellPositions();
	int id;
	map<int, vector<Position>> cells;
private:
	int cellSize;
	int rotationState;
	vector<SDL_Color> colors;
	int rowOffset;
	int columnOffset;
};