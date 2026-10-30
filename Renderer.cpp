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
	while (true) {

	}
}
void Renderer::processEvents(GameEngine& game) {
    while (const std::optional<sf::Event> event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mousePressed->button == sf::Mouse::Button::Left)
            {
                handleRowPress(game);
            }
        }
    }
}
void Renderer::render(GameEngine& game);
void Renderer::renderMainMenu(GameEngine& game);

void Renderer::mainMenu(GameEngine& game) {
    while (true) {
        
    }
}
void Renderer::drawBoard(const Board& board);
void Renderer::drawTetromino(Tetromino& currentBlock);