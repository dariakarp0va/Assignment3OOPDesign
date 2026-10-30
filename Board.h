#pragma once
#include<vector>
#include "Tetromino.h"
#include "const.h"


class Board {
private:
	std::vector<std::vector<int>> grid;
	Tetromino currentBlock;
public:
	Board();
	Tetromino& getCurrentBlock();
	bool checkCollision();
	int clearLines();
	void mergeBlock();
	void setNewTetromino(Tetromino& tetromino);
};