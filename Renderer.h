#pragma once


#include <SFML/Graphics.hpp>
#include <optional>
#include "GameEngine.h"

class Renderer {
private:
    
    bool inMenu = true;

    sf::RenderWindow window;
    sf::Font font;
    bool fontLoaded;

    sf::Clock clock;
    float timer = 0.f;
    const float delay = 1.f;

    void processEvents(GameEngine& game);
    void render(GameEngine& game);
    void renderMainMenu(GameEngine& game);
    void handleRowPress(GameEngine& game);
    void drawTetromino(const Tetromino& currentBlock);
    void renderGameOver(GameEngine& game);
    void renderGame(GameEngine& game);

public:
    Renderer();
    void drawBoard(const Board& board);
    void run(GameEngine& game);

};

