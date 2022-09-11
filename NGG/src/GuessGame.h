#pragma once

class GuessGame
{
public:
	int RndNum();
	bool CheckGuess(int& g);
	void Run();
	void Reset();
	void OutOfTries();
	void Introduce();

private:
	int secretNum = 0;
	int tries = 5;
	int guess = 0;
	int score = 0;
	int playAgain = 0;
	bool isPlaying = true;
};