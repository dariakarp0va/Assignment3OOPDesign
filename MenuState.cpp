#include "MenuState.h"

GameState MenuState::state() const { return GameState::Menu; }
void MenuState::start(GameEngine& e) {
	e.tryStart();
}
void MenuState::move(GameEngine& e, int dir) {}
void MenuState::rotate(GameEngine& e) {}
void MenuState::speedUp(GameEngine& e) {}