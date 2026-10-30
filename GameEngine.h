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
public:
	GameEngine();
	void startGame();
	void moveTetromino(int direction);
	void rotateTetromino();
	void clearLines();
	void SpeedUpTetromino();
	void SaveGame();
	void LoadGame();
};