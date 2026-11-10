#include "GameOverState.h"

GameState GameOverState::state() const { return GameState::GameOver; }
void GameOverState::start(GameEngine& e) {
	e.tryStart();
}
void GameOverState::move(GameEngine& e, int dir) {}
void GameOverState::rotate(GameEngine& e) {}
void GameOverState::speedUp(GameEngine& e) {}