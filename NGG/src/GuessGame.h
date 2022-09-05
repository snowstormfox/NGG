#pragma once
#include <string>

class GuessGame
{
public:
	// Constructor
	GuessGame();

	// Destructor
	~GuessGame();

	void rndNum();
	bool checkGuess(int& g);
	void Run();

private:
	int secretNum = 0;
	int tries = 8;
	int guess = 0;
};