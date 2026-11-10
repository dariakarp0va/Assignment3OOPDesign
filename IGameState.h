#pragma once

class GameEngine;

enum class GameState { Menu, Playing, GameOver };

class IGameState {
public:
    virtual GameState state() const = 0;
    virtual void start(GameEngine& e) = 0;
    virtual void move(GameEngine& e, int dir) = 0;
    virtual void rotate(GameEngine& e) = 0;
    virtual void speedUp(GameEngine& e) = 0;
    virtual ~IGameState() = default;
};
