#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <optional>

Renderer::Renderer(){}
Renderer::Renderer()
    : window(sf::VideoMode({ 300, 600 }), "Tetris"),
    fontLoaded(font.openFromFile("arial.ttf"))     
{
    window.setFramerateLimit(60);
}
void Renderer::startGame(GameEngine& game) {
    while (window.isOpen()) {
        processEvents(game);
        render(game);
    }
}
void Renderer::processEvents(GameEngine& game) {
    while (const std::optional<sf::Event> event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->code == sf::Keyboard::Key::A)
            {
                game.moveTetromino(-1);
            }
            else if (keyPressed->code == sf::Keyboard::Key::D) {
                game.moveTetromino(1);
            }
            else if (keyPressed->code == sf::Keyboard::Key::S) {
                game.SpeedUpTetromino();
            }
        }
    }
}
void Renderer::render(GameEngine& game) {

}
void Renderer::renderMainMenu(GameEngine& game) {

}

void Renderer::mainMenu(GameEngine& game) {
    while (true) {
        processEvents(game);
    }
}
void Renderer::drawBoard(const Board& board) {

}
void Renderer::drawTetromino(Tetromino& currentBlock) {

}