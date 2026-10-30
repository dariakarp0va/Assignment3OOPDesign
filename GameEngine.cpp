#include "GameEngine.h"
#include <sstream>
#include <fstream>

GameEngine::GameEngine() {
}
void GameEngine::startGame() {
    isGameOver = false;
    board.setNewTetromino(creater.createRandomTetromino());
}

void GameEngine::moveTetromino(int direction) {
    Tetromino& current = board.getCurrentBlock();

    current.move(direction, 0);

    if (board.checkCollision()) {
        current.move(-direction, 0);
    }
}

void GameEngine::rotateTetromino() {
    Tetromino& current = board.getCurrentBlock();

    current.rotate();

    if (board.checkCollision()) {
        for (int i = 0; i < 3; i++) {
            current.rotate();
        }
    }
}

void GameEngine::clearLines() {
    board.clearLines();
}

void GameEngine::SpeedUpTetromino() {
    Tetromino& current = board.getCurrentBlock();

    current.speedUp();

    if (board.checkCollision()) {
        current.move(0, -1);
        board.mergeBlock();
        int cleardLines = board.clearLines();
        score.addPoints(cleardLines);

        board.setNewTetromino(creater.createRandomTetromino());


    }
}

void GameEngine::SaveGame() {
    score.saveBestScore();
    
}

void GameEngine::LoadGame() {
    score.loadBestScore();
}