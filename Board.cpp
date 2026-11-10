#include "Board.h"


Board::Board() : grid(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0)), currentBlock({ {0} }) {}

bool Board::checkCollision() {
	std::vector<std::vector<int>> type = currentBlock.getType();

	for (int i = 0; i < type.size(); i++) {
		for (int j = 0; j < type.size(); j++) {
			if (type[i][j] != 0) {
				int onGridX = j + currentBlock.getX();
				int onGridY = i + currentBlock.getY();
				if (onGridX >= BOARD_WIDTH || onGridY >= BOARD_HEIGHT || onGridX < 0 || onGridY < 0 || grid[onGridY][onGridX] != 0) {
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

	
	for (int i = 0; i < type.size(); i++) {
		for (int j = 0; j < type.size(); j++) {
			if (type[i][j] != 0) {
				int onGridX = j + currentBlock.getX();
				int onGridY = i + currentBlock.getY();
				grid[onGridY][onGridX] = type[i][j];
			}
		}
	}
}

Tetromino& Board::getCurrentBlock() {
	return currentBlock;
}
const Tetromino& Board::getCurrentBlock() const {
	return currentBlock;
}

void Board::setNewTetromino(const Tetromino& tetromino) {
	currentBlock = tetromino;
}

std::vector<std::vector<int>> Board::getGrid() const{
	return grid;
}
  