#include "TetrominoCreater.h"
#include "Tetromino.h"
#include<random>

std::random_device rd;
std::mt19937 gen(rd());

enum Types {
	i_block = 1,
	z_block,
	s_block,
	l_block,
	j_block,
	t_block,
	o_block,
	dot_block
};
TetrominoCreater::TetrominoCreater() {
	
}

Tetromino TetrominoCreater::createRandomTetromino() {
	std::uniform_int_distribution<> dis(1, 8);

	int randomValue = dis(gen);

	switch (randomValue) {
	case 1: {
		return Tetromino({ {1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} });
	}
	case 2: {
		return Tetromino({ {2,2,0}, {0,2,2}, {0,0,0} });
	}
	case 3: {
		return Tetromino({ {0,3,3}, {3,3,0}, {0,0,0} });
	}
	case 4: {
		return Tetromino({ {4,4,4}, {0,0,4}, {0,0,0} });
	}
	case 5: {
		return Tetromino({ {5,5,5}, {5,0,0}, {0,0,0} });
	}
	case 6: {
		return Tetromino({ {6,6,6}, {0,6,0}, {0,0,0} });
	}
	case 7: {
		return Tetromino({ {7,7}, {7,7}});
	}
	case 8: {
		return Tetromino({ {8} });
	}
	}
	return Tetromino({ {0} });
}