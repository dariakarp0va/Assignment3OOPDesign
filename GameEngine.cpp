#include "GameEngine.h"
#include"PlayingState.h"
#include"MenuState.h"
#include"GameOverState.h"

GameEngine::GameEngine(): state(std::make_unique<MenuState>()) {

}
void GameEngine::startGame() {
    state->start(*this);
}

void GameEngine::moveTetromino(int direction) {
    state->move(*this, direction);
}

void GameEngine::rotateTetromino() {
    state->rotate(*this);
}


void GameEngine::SpeedUpTetromino() {
    state->speedUp(*this);
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
const Score& GameEngine::getScore() const {
    return score;
}


void GameEngine::tryMove(int dir) {
    Tetromino& current = board.getCurrentBlock();

    current.move(dir, 0);

    if (board.checkCollision()) {
        current.move(-dir, 0);
    }
}
void GameEngine::tryRotate() {
    Tetromino& current = board.getCurrentBlock();

    current.rotate();

    if (board.checkCollision()) {
        for (int i = 0; i < 3; i++) {
            current.rotate();
        }
    }
}
void GameEngine::trySpeedUp() {
    Tetromino& current = board.getCurrentBlock();
    current.speedUp();
    if (board.checkCollision()) {
        current.move(0, -1);
        board.mergeBlock();
        score.addPoints(board.clearLines());
        board.setNewTetromino(creater.createRandomTetromino());
        if (board.checkCollision()) {
            SaveGame();
            setState(std::make_unique<GameOverState>());
        }
    }
}
void GameEngine::tryStart() {
    board = Board();
    score = Score();
    score.loadBestScore();
    setState(std::make_unique<PlayingState>());
    board.setNewTetromino(creater.createRandomTetromino());
    if (board.checkCollision()) {
        setState(std::make_unique<GameOverState>());
        SaveGame();
    }
}

GameState GameEngine::getState() const {
    return state->state();
}

void GameEngine::setState(std::unique_ptr<IGameState> newState) {
    state = std::move(newState);
}