#include <sstream>
#include <fstream>
#include "Score.h"


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

void Score::addPoints(int linesCleared) {
    switch (linesCleared) {
    case 1: {
        currentScore += 100;
        break;
    }
    case 2: {
        currentScore += 300;
        break;
    }
    case 3: {
        currentScore += 500;
        break;
    }
    case 4: {
        currentScore += 800;
        break;
    }
    default: {
        break;
    }
    }
}
void Score::saveBestScore() {
	if (currentScore > bestScore) {
		bestScore = currentScore;
	}
    std::ofstream outFile("bestScore.txt");

    if (!outFile.is_open()) {
        printf("Issues with opening file\n");
        return;
    }
    outFile << bestScore;
    outFile << "\n";
}
void Score::loadBestScore() {
    std::ifstream inFile("bestScore.txt");
    if (!inFile.is_open()) {
        printf("Issues with opening file\n");
        return;
    }
    std::string line;
    std::getline(inFile, line);
    bestScore = convertIntoDigit(line);
}
int Score::showBestScore() {
	return bestScore;
}

int Score::showCurrentScore() {
    return currentScore;
}

void Score::resetCurrentScore() {
    currentScore = 0;
}