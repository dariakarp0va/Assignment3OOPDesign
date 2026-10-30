#include "Tetromino.h"

Tetromino::Tetromino(std::vector<std::vector<int>> type = { {0} }) {
	x = 5;
	y = 0;
}

void Tetromino::rotate() {
	for (int i = 0; i < tetrominoType.size(); i++) {
		for (int j = i + 1; j < tetrominoType.size(); j++) {
			int temp = tetrominoType[i][j];
			tetrominoType[i][j] = tetrominoType[j][i];
			tetrominoType[j][i] = temp;
		}
	}

	for (int i = 0; i < tetrominoType.size(); i++) {
		for (int j = 0; j < tetrominoType.size() / 2; j++) {
			int temp = tetrominoType[i][j];

			tetrominoType[i][j] = tetrominoType[i][tetrominoType.size() - 1 - j];
			tetrominoType[i][tetrominoType.size() - 1 - j] = temp;
		}
	}
}

void Tetromino::move(int x_, int y_) {
	x += x_;
	y += y_;
}

void Tetromino::speedUp() {
	y += 1;
}


int Tetromino::getX() {
	return x;
}

int Tetromino::getY() {
	return y;
}

std::vector<std::vector<int>> Tetromino::getType() {
	return tetrominoType;
}