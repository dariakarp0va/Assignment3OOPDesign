#pragma once
#include <vector>

class Tetromino {
private:
	int x = 0;
	int y = 0;
	std::vector<std::vector<int>> tetrominoType;
public:
	Tetromino(std::vector<std::vector<int>> type);
	void rotate();
	void move(int x_, int y_);
	void speedUp();
	int getX();
	int getY();
	std::vector<std::vector<int>> getType();
};
