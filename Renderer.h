#pragma once


#include <SFML/Graphics.hpp>
#include <optional>
#include "GameEngine.h"

class Renderer {
private:
    const int windowSize = 600; 
    const int TetrominoSize = 30;
    bool inMenu = true;

    sf::RenderWindow window;
    sf::Font font;
    bool fontLoaded;

    void startGame(GameEngine& game);
    void processEvents(GameEngine& game);
    void render(GameEngine& game);
    void renderMainMenu(GameEngine& game);
    void processEventsInMenu(GameEngine& game);
    void handleRowPress(GameEngine& game);
    void drawTetromino(Tetromino& currentBlock);

public:
    Renderer();
    void mainMenu(GameEngine& game);
    void drawBoard(const Board& board);
    void drawBlock(Tetromino& currentBlock);
};

