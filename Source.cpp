#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <optional>

int convertIntoDigit(std::string lineNum)
{
    bool isDigit = false;
    while (!isDigit)
    {
        bool isSymbolDigit = true;
        for (int i = 0; i < lineNum.length(); i++)
        {
            if (!isdigit(lineNum[i]))
            {
                isSymbolDigit = false;
            }
        }
        isDigit = isSymbolDigit;
        if (isDigit == false)
        {
            printf("input should be numeric \n");
            return -1;
        }
    }
    try {
        return std::stoi(lineNum);
    }
    catch (const std::exception& e) {
        printf("number is too large\n");
        return -1;
    }
}

enum class Player
{
    None,
    X,
    O
};

class TicTacToe {
public:
    TicTacToe() : actionsNumber(0), currentPlayer(Player::X), winner(Player::None)
    {
        resetBoard();
    }

    void reset()
    {
        resetBoard();
        actionsNumber = 0;
        currentPlayer = Player::X;
        winner = Player::None;
    }

    bool isGameOver() const
    {
        return winner != Player::None || actionsNumber >= 9;
    }

    Player getCurrentPlayer() const
    {
        return currentPlayer;
    }

    Player getWinner() const
    {
        return winner;
    }

    void makeMove(int row, int col)
    {
        if (!isGameOver() && row >= 0 && row < gridSize && col >= 0 && col < gridSize && board[row][col] == Player::None)
        {
            board[row][col] = currentPlayer;
            checkForWinner(row, col);
            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
            actionsNumber++;
            return;
        }

        reset();
    }

    Player getCell(int row, int col) const
    {
        return board[row][col];
    }

private:
    const int gridSize = 3;
    int actionsNumber = 0;
    Player currentPlayer;
    Player winner;
    std::vector<std::vector<Player>> board;

    void resetBoard()
    {
        board = std::vector<std::vector<Player>>(gridSize, std::vector<Player>(gridSize, Player::None));
    }

    void checkForWinner(int lastMoveRow, int lastMoveCol)
    {
        // Перевірка рядка
        if (board[lastMoveRow][0] == board[lastMoveRow][1] && board[lastMoveRow][1] == board[lastMoveRow][2])
        {
            winner = board[lastMoveRow][0];
        }

        // Перевірка стовпця
        if (board[0][lastMoveCol] == board[1][lastMoveCol] && board[1][lastMoveCol] == board[2][lastMoveCol])
        {
            winner = board[0][lastMoveCol];
        }

        // Перевірка діагоналей
        if ((lastMoveRow == lastMoveCol || lastMoveRow + lastMoveCol == gridSize - 1) &&
            ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
                (board[0][2] == board[1][1] && board[1][1] == board[2][0])))
        {
            winner = board[1][1];
        }
    }
};

class Renderer {
public:
    Renderer()
        : windowSize(300),
        cellSize(windowSize / 3),
        window(sf::VideoMode({ static_cast<unsigned int>(windowSize), static_cast<unsigned int>(windowSize) }), "Tic-Tac-Toe"),
        font(),
        fontLoaded(font.openFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) 
    {
        window.setFramerateLimit(60);
    }

    void run(TicTacToe& game)
    {
        while (window.isOpen())
        {
            processEvents(game);
            render(game);
        }
    }

private:
    const int windowSize;
    const int cellSize;

    sf::RenderWindow window;
    sf::Font font;
    bool fontLoaded;

    void processEvents(TicTacToe& game)
    {
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
                    handleMouseClick(game, mousePressed->position.x, mousePressed->position.y);
                }
            }
        }
    }

    void handleMouseClick(TicTacToe& game, int mouseX, int mouseY)
    {
        int row = mouseY / cellSize;
        int col = mouseX / cellSize;
        game.makeMove(row, col);
    }

    void render(const TicTacToe& game)
    {
        window.clear();

        // Малюємо сітку
        for (int i = 1; i < 3; ++i) {
            sf::Vertex line[] = {
                sf::Vertex{sf::Vector2f(static_cast<float>(i * cellSize), 0.f)},
                sf::Vertex{sf::Vector2f(static_cast<float>(i * cellSize), static_cast<float>(windowSize))},
                sf::Vertex{sf::Vector2f(0.f, static_cast<float>(i * cellSize))},
                sf::Vertex{sf::Vector2f(static_cast<float>(windowSize), static_cast<float>(i * cellSize))}
            };
            window.draw(line, 4, sf::PrimitiveType::Lines);
        }

        // Малюємо X та O відповідно до стану дошки
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (game.getCell(row, col) == Player::X) {
                    drawX(row, col);
                }
                else if (game.getCell(row, col) == Player::O) {
                    drawO(row, col);
                }
            }
        }

        // Повідомлення про переможця
        if (game.getWinner() != Player::None || game.isGameOver()) {
            if (fontLoaded)
            {
                sf::Text text(font);
                text.setCharacterSize(30);
                text.setFillColor(sf::Color::White);

                std::string answer = (game.getWinner() == Player::X ? "Player X" : "Player O") + std::string(" wins!\nClick to restart.");
                if (game.getWinner() == Player::None)
                {
                    answer = "Draw!\nClick to restart.";
                }

                text.setString(answer);
                text.setPosition(sf::Vector2f(10.f, 10.f));
                window.clear();
                window.draw(text);
            }
        }

        window.display();
    }

    void drawX(int row, int col)
    {
        sf::Vertex line1[] = {
            sf::Vertex{sf::Vector2f(static_cast<float>(col * cellSize + 10), static_cast<float>(row * cellSize + 10))},
            sf::Vertex{sf::Vector2f(static_cast<float>((col + 1) * cellSize - 10), static_cast<float>((row + 1) * cellSize - 10))}
        };
        sf::Vertex line2[] = {
            sf::Vertex{sf::Vector2f(static_cast<float>((col + 1) * cellSize - 10), static_cast<float>(row * cellSize + 10))},
            sf::Vertex{sf::Vector2f(static_cast<float>(col * cellSize + 10), static_cast<float>((row + 1) * cellSize - 10))}
        };

        window.draw(line1, 2, sf::PrimitiveType::Lines);
        window.draw(line2, 2, sf::PrimitiveType::Lines);
    }

    void drawO(int row, int col)
    {
        sf::CircleShape circle(static_cast<float>(cellSize / 2 - 10));
        circle.setPosition(sf::Vector2f(static_cast<float>(col * cellSize + 10), static_cast<float>(row * cellSize + 10)));
        circle.setOutlineThickness(10.f);
        circle.setOutlineColor(sf::Color::White);
        circle.setFillColor(sf::Color::Transparent);

        window.draw(circle);
    }
};

int main()
{
    TicTacToe game;
    Renderer renderer;
    renderer.run(game);

    return 0;
}