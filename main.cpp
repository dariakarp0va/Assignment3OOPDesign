#include "GameEngine.h"
#include "Renderer.h"
#include <ctime>
#include <cstdlib>

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

int main(){
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	GameEngine game;
	Renderer renderer;

	renderer.mainMenu(game);
	return 0;
}