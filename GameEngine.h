#pragma once
#include "Board.h"
#include "TetrominoCreater.h"
#include "Score.h"
#include "IGameState.h"
#include <memory>

class GameEngine {
private:
	Board board;
	Score score;
	TetrominoCreater creater;
	std::unique_ptr<IGameState> state;

	void setState(std::unique_ptr<IGameState> newState);

public:
	GameEngine();
	void startGame();
	void moveTetromino(int direction);
	void rotateTetromino();
	void SpeedUpTetromino();
	void SaveGame();
	void LoadGame();
	const Board& getBoard() const;
	const Score& getScore() const;
	GameState getState() const;

	void tryMove(int dir);
	void tryRotate();
	void trySpeedUp();
	void tryStart();
};