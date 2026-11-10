#include "PlayingState.h"

GameState PlayingState::state() const { return GameState::Playing; }
void PlayingState::start(GameEngine&) {}
void PlayingState::move(GameEngine& e, int dir) { 
	e.tryMove(dir); 
}
void PlayingState::rotate(GameEngine& e) { 
	e.tryRotate();
}
void PlayingState::speedUp(GameEngine& e) { 
	e.trySpeedUp();
}