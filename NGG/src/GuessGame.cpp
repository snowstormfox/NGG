#include "GuessGame.h"
#include <string>
#include <iostream>

int GuessGame::RndNum()
{
	srand((unsigned)time(0));
	secretNum = rand() % 100 + 1;
	return secretNum;
}

bool GuessGame::CheckGuess(int& g)
{
	if (g > secretNum)
	{
		std::cout << "Your guess is too high!\n\n";
		return false;
	}

	else if (g < secretNum)
	{
		std::cout << "Your guess is too low!\n\n";
		return false;
	}

	else
	{
		std::cout << "Congratulations! You have guessed the correct number,\n";
		std::cout << "You guessed the number with " << tries << " tries left.\n\n";
		return true;
	}
}

void GuessGame::Introduce()
{
	std::cout << "Number Guessing Game\n";
	std::cout << "You have 8 tries.\n\n";
	RndNum();
}

void GuessGame::Reset()
{
	tries = 5;
	score = 0;
}

void GuessGame::OutOfTries()
{
	std::cout << "Game Over!\n";
	std::cout << "The correct number was: " << secretNum << "\n";
	std::cout << "Your score was: " << score << "\n";
	std::cout << "Do yo want to play again (1 for yes, and 0 for no)? ";
	std::cin >> playAgain;

	if (playAgain == 1)
	{
		Reset();
		Run();
	}

	else 
	{
		isPlaying = false;
	}
}

void GuessGame::Run()
{
	Introduce();

	while (isPlaying)
	{
		std::cout << "Enter a guess between 1 and 100: ";
		std::cin >> guess;
		tries--;

		if (CheckGuess(guess))
		{
			score++;
			tries = 5;
			RndNum();
			continue;
		}

		else if (tries == 0)
		{
			OutOfTries();
		}
	}
}
