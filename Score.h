#pragma once


class Score {
private:
	int currentScore = 0;
	int bestScore = 0;
public:
	void addPoints(int linesCleared);
	void saveBestScore();
	void loadBestScore();
	int showBestScore();
};