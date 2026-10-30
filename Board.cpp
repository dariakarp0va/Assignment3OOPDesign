#include "Board.h"


Board::Board() : grid(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0)), currentBlock({ {0} }) {}

bool Board::checkCollision() {
	std::vector<std::vector<int>> type = currentBlock.getType();

	for (int i = currentBlock.getX(); i < currentBlock.getX() + type.size(); i++) {
		for (int j = currentBlock.getY(); j < currentBlock.getY() + type.size(); j++) {
			if (type[j - currentBlock.getY()][i - currentBlock.getX()] != 0) {
				if ( i >= BOARD_WIDTH || j >= BOARD_HEIGHT || i < 0 || j < 0 ||  grid[j][i] != 0){
					return true;
				}
			}
		}
	}
	return false;
}

int Board::clearLines() {
	int clearedLines = 0;
	for (int i = BOARD_HEIGHT - 1; i >= 0; i--) {
		bool is_filled = true;
		for (int j = 0; j < BOARD_WIDTH; j++) {
			if (grid[i][j] == 0){
				is_filled = false;
			}
		}
		if (is_filled) {
			grid.erase(grid.begin() + i);
			clearedLines++;
			i++;
			grid.insert(grid.begin(), { 0,0,0,0,0,0,0,0,0,0 });
		}

	} 
	return clearedLines;
}

void Board::mergeBlock() {
	std::vector<std::vector<int>> type = currentBlock.getType();

	for (int i = currentBlock.getX(); i < currentBlock.getX() + type.size(); i++) {
		for (int j = currentBlock.getY(); j < currentBlock.getY() + type.size(); j++) {
			if (type[j - currentBlock.getY()][i - currentBlock.getX()] != 0) {
				grid[j][i] = type[j - currentBlock.getY()][i - currentBlock.getX()];
			}
		}
	}
}

Tetromino& Board::getCurrentBlock() {
	return currentBlock;
}

void Board::setNewTetromino(Tetromino& tetromino) {
	currentBlock = tetromino;
}
  