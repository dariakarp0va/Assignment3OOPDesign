#pragma once
#include "GameEngine.h"
#include"IGameState.h"


class MenuState : public IGameState {
public:
    GameState state() const override;
    void start(GameEngine& e) override;
    void move(GameEngine& e, int dir) override;
    void rotate(GameEngine& e) override;
    void speedUp(GameEngine& e) override;
    ~MenuState() = default;
};