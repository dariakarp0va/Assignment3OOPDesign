#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <optional>


Renderer::Renderer()
    : window(sf::VideoMode({ 300, 750 }), "Tetris"),
    fontLoaded(font.openFromFile("C:\brbbr\arial.ttf"))     
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
            else if (keyPressed->code == sf::Keyboard::Key::W) {
                game.rotateTetromino();
            }
            else if (keyPressed->code == sf::Keyboard::Key::Escape) { 
                game.SaveGame();
                window.close();
            }
        }
    }
}
void Renderer::processEventsInMenu(GameEngine& game) {
    bool inMenu = true;
    while (const std::optional<sf::Event> event = window.pollEvent())
    {
        if (!inMenu) {
            break;
        }
        else if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->code == sf::Keyboard::Key::Space) {
                game.startGame();
            }
            else if (keyPressed->code == sf::Keyboard::Key::Escape) {
                game.SaveGame();
                window.close();
            }
        }
    }
    
}
void Renderer::render(GameEngine& game){
    window.clear(sf::Color::Black);

    sf::RectangleShape block(sf::Vector2f(10.f, 10.f));
    block.setPosition(sf::Vector2f(90.f, 0.f));
    block.setFillColor(sf::Color::Blue);

    sf::Text info(font);
    info.setCharacterSize(25);
    info.setFillColor(sf::Color::White);
    info.setString("i");
    info.setPosition(sf::Vector2f(90.f, 0.f));

    if (fontLoaded) {
        sf::Text scores(font);
        scores.setCharacterSize(25);
        scores.setFillColor(sf::Color::White);
        scores.setString("SCORE: " + std::to_string(game.getScore().showCurrentScore()) + "    BEST: " + std::to_string(game.getScore().showBestScore()));
        scores.setPosition(sf::Vector2f(10.f, 35.f));
        window.draw(scores);
    }

    drawBoard(game.getBoard());
    drawTetromino(game.getBoard().getCurrentBlock());



    window.draw(block);
    window.draw(info);

    window.display();
}
void Renderer::renderMainMenu(GameEngine& game) {
    window.clear(sf::Color::Black);
    sf::Text text(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setString("TETRIS");
    text.setPosition(sf::Vector2f(46.f, 40.f));

    sf::Text start(font);
    start.setCharacterSize(25);
    start.setFillColor(sf::Color::White);
    start.setString("Press SPACE to start the game");
    start.setPosition(sf::Vector2f(46.f, 150.f));

    window.draw(text);
    window.draw(start);
    window.display();
}

void Renderer::mainMenu(GameEngine& game) {
    while (window.isOpen()) {
        processEventsInMenu(game);
        renderMainMenu(game);
    }
}
void Renderer::drawBoard(const Board& board) {
    sf::RectangleShape board_back(sf::Vector2f(10.f, 10.f));
    board_back.setPosition(sf::Vector2f(90.f, 0.f));
    board_back.setFillColor(sf::Color::Blue);

}
void Renderer::drawTetromino(Tetromino& currentBlock) {

    sf::RectangleShape block(sf::Vector2f(10.f, 10.f));

    for (int i = 0; i < currentBlock.getType().size(); ) {

    }
}