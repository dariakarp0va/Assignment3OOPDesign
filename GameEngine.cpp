#include "GameEngine.h"
#include <sstream>
#include <fstream>

GameEngine::GameEngine() {
}
void GameEngine::startGame() {
    board = Board();
    score = Score();
    isGameOver = false;
    score.loadBestScore();
    board.setNewTetromino(creater.createRandomTetromino());
    if (board.checkCollision()) {
        isGameOver = true;
        SaveGame();
        score.resetCurrentScore();
    }
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

        if (board.checkCollision()) {
            isGameOver = true;
            SaveGame();
            score.resetCurrentScore();
        }


    }
}

void GameEngine::SaveGame() {
    score.saveBestScore();
}

void GameEngine::LoadGame() {
    score.loadBestScore();
}

const Board& GameEngine::getBoard() const { 
    return board;
}
Score& GameEngine::getScore() {
    return score; 
}

bool GameEngine::getGameStatus() {
    return isGameOver;
}