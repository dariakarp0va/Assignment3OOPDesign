#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <optional>


Renderer::Renderer()
    : window(sf::VideoMode({ windowWidth, windowHeigth}), "Tetris"),
    fontLoaded(font.openFromFile("C:\\brbbr\\arial.ttf"))     
{
    window.setFramerateLimit(60);
}
void Renderer::startGame(GameEngine& game) {
    game.startGame();
    sf::Clock clock;
    float timer = 0.f;
    float delay = 1.f;

    while (window.isOpen() && game.getState() == GameState::Playing) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        processEvents(game);

        if (timer > delay) {
            game.SpeedUpTetromino();
            timer = 0.f;
        }
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
            else if (keyPressed->code == sf::Keyboard::Key::Space) {
                startGame(game);
            }
        }
    }
}

void Renderer::run(GameEngine& game) {
    while (window.isOpen()) {
        render(game);
        processEvents(game);
    }
}

void Renderer::renderGame(GameEngine& game){
    window.clear(sf::Color::Black);

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


    window.display();
}

void Renderer::renderGameOver(GameEngine& game) {
    window.clear(sf::Color::Black);
    sf::Text text(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setString("GAME OVER");
    text.setPosition(sf::Vector2f(46.f, 40.f));

    sf::Text start(font);
    start.setCharacterSize(25);
    start.setFillColor(sf::Color::White);
    start.setString("Press SPACE to restart the game");
    start.setPosition(sf::Vector2f(46.f, 150.f));

    window.draw(text);
    window.draw(start);
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



void Renderer::render(GameEngine& game) {
 
    switch (game.getState()) {
    case GameState::Menu:
    renderMainMenu(game);
    break;
    case GameState::Playing:
    renderGame(game);
    break;
    case GameState::GameOver:
    renderGameOver(game);
    break;
    }
    
}
void Renderer::drawBoard(const Board& board) {

    sf::RectangleShape board_back(sf::Vector2f(300.f, 600.f));
    board_back.setPosition(sf::Vector2f(50.f, 100.f));
    board_back.setFillColor(sf::Color(50, 50, 50));
    window.draw(board_back);

    std::vector<std::vector<int>> grid = board.getGrid();

    for (int j = 0; j < grid.size(); j++) {
        for (int i = 0; i < grid[j].size(); i++) {
            if (grid[j][i] != 0) {
                sf::RectangleShape block(sf::Vector2f(30.f, 30.f));
                block.setPosition(sf::Vector2f((i * TetrominoSize) + 50.f, (j * TetrominoSize) + 100.f));
                switch (grid[j][i]) {
                case (1): {
                    block.setFillColor(sf::Color::Cyan);
                    break;
                }
                case (2): {
                    block.setFillColor(sf::Color::Red);
                    break;
                }
                case (3): {
                    block.setFillColor(sf::Color::Green);
                    break;
                }
                case (4): {
                    block.setFillColor(sf::Color(255, 165, 0)); // orange
                    break;
                }
                case (5): {
                    block.setFillColor(sf::Color::Blue);
                    break;
                }
                case (6): {
                    block.setFillColor(sf::Color(128, 0, 128)); // purple
                    break;
                }
                case (7): {
                    block.setFillColor(sf::Color::Yellow);
                    break;
                }
                case (8): {
                    block.setFillColor(sf::Color::Magenta);
                    break;
                }
                }
                window.draw(block);
            }
        }
    }

    
}
void Renderer::drawTetromino(const Tetromino& currentBlock) {

    for (int i = 0; i < currentBlock.getType().size(); i++) {
        for (int j = 0; j < currentBlock.getType().size(); j++) {
            if (currentBlock.getType()[i][j] != 0) {
                sf::RectangleShape block(sf::Vector2f(30.f, 30.f));
                block.setPosition(sf::Vector2f((currentBlock.getX() + j) * 30 + 50, (currentBlock.getY() + i) * 30 + 100));
                switch (currentBlock.getType()[i][j]) {
                case (1): {
                    block.setFillColor(sf::Color::Cyan);
                    break;
                }
                case (2): {
                    block.setFillColor(sf::Color::Red);
                    break;
                }
                case (3): {
                    block.setFillColor(sf::Color::Green);
                    break;
                }
                case (4): {
                    block.setFillColor(sf::Color(255, 165, 0)); // orange
                    break;
                }
                case (5): {
                    block.setFillColor(sf::Color::Blue);
                    break;
                }
                case (6): {
                    block.setFillColor(sf::Color(128, 0, 128)); // purple
                    break;
                }
                case (7): {
                    block.setFillColor(sf::Color::Yellow);
                    break;
                }
                case (8): {
                    block.setFillColor(sf::Color::Magenta);
                    break;
                }
                default: {
                    block.setFillColor(sf::Color::White);
                }
                }
                window.draw(block);
            }
        }
    }
}