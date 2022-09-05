#include "GuessGame.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

GuessGame::GuessGame()
{

}

GuessGame::~GuessGame()
{
	std::cout << "Object destroyed\n";
}

void GuessGame::rndNum()
{
	srand((unsigned)time(0)); //seed random number generator
	secretNum = rand() % 100 + 1; // random number between 1 and 100
}

bool GuessGame::checkGuess(int& g)
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

void GuessGame::Run()
{
	std::cout << "Number Guessing Game\n\n";
	rndNum();

	while (guess != secretNum)
	{
		std::cout << "Enter a guess between 1 and 100: ";
		std::cin >> guess;
		tries--;

		if (checkGuess(guess))
		{
			//score++;
			break;
		}

		else if (tries == 0)
		{
			std::cout << "Game Over!\nYour score was: "/* << score*/;
			//Fråga om spelaren vill köra igen eller avsluta
		}
	}

	std::cin.get();
}
