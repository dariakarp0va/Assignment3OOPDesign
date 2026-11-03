#pragma once
#include "Board.h"
#include "TetrominoCreater.h"
#include "Score.h"


class GameEngine {
private:
	Board board;
	Score score;
	TetrominoCreater creater;
	bool isGameOver = 0;
	const float blockSize = 30.f;
public:
	GameEngine();
	void startGame();
	void moveTetromino(int direction);
	void rotateTetromino();
	void clearLines();
	void SpeedUpTetromino();
	void SaveGame();
	void LoadGame();
	Board& getBoard();
	Score& getScore();
};