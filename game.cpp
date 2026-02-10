#include "game.hpp"
#include <random>


Game::Game() {
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
	score = 0;
	scoreChanged = false;
}

Block Game::GetRandomBlock() {
	if (blocks.empty()) {
		blocks = GetAllBlocks();
	}
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, blocks.size() - 1);
	int randomIndex = dis(gen);
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

vector<Block> Game::GetAllBlocks() {
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Draw(SDL_Renderer* renderer) {
	grid.Draw(renderer);
	currentBlock.Draw(renderer, 11, 11);
	switch (nextBlock.id)
	{
	case 3:
		nextBlock.Draw(renderer, 255, 290);
		break;
	case 4:
		nextBlock.Draw(renderer, 255, 280);
		break;
	default:
		nextBlock.Draw(renderer, 270, 270);
		break;
	}
}

void Game::HandleInput() {
	SDL_PumpEvents();
	const bool* keys = SDL_GetKeyboardState(NULL);

	if (gameOver && keys[SDL_SCANCODE_SPACE])
	{
		gameOver = false;
		Reset();
	}

	if (keys[SDL_SCANCODE_LEFT]) {
		MoveBlockLeft();
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		MoveBlockRight();
	}
	if (keys[SDL_SCANCODE_DOWN]) {
		MoveBlockDown();
		UpdateScore(0, 1);
	}
	if (keys[SDL_SCANCODE_UP]) {
		RotateBlock();
	}
}

void Game::MoveBlockLeft() {
	if (!gameOver) {
		currentBlock.Move(0, -1);
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight() {
	if (!gameOver) {
		currentBlock.Move(0, 1);
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown() {
	if (!gameOver) {
		currentBlock.Move(1, 0);
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

bool Game::IsBlockOutside() {
	vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if (grid.IsCellOutside(item.row, item.column)) {
			return true;
		}
	}
	return false;
}

void Game::RotateBlock() {
	if (!gameOver) {
		currentBlock.Rotate();
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.UndoRotation();
		}
	}
}

void Game::LockBlock() {
	vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (BlockFits() == false) {
		gameOver = true;
	}
	nextBlock = GetRandomBlock();
	int rowsCleared = grid.ClearFullRows();
	UpdateScore(rowsCleared, 0);
}

bool Game::BlockFits() {
	vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if (grid.IsCellEmpty(item.row, item.column) == false) {
			return false;
		}
	}
	return true;
}

void Game::Reset() {
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints) {
	int oldScore = score; // Сохраняем старый счёт для проверки изменений
	switch (linesCleared) {
	case 1:
		score += 40;
		break;
	case 2:
		score += 100;
		break;
	case 3:
		score += 300;
		break;
	case 4:
		score += 1200;
		break;
	default:
		break;
	}
	score += moveDownPoints;
	// Устанавливаем флаг только если счёт действительно изменился
	scoreChanged = (score != oldScore);
}