#include <iostream>
#include <string>
#include "FBullCowGame.h"

using int32 = int;
using FText = std::string;

// Prototypes

void PrintIntroduction();
void PlayGame();
bool AskToPlayAgain();
FText ReadGuess();
void PrintGuess(FText);
FText GetAndPrintGuess();

// Globals

FBullCowGame BCGame;

int main()
{
	bool bPlayAgain = true;
	while (bPlayAgain == true)
	{
		PrintIntroduction();
		PlayGame();
		if (AskToPlayAgain() == false)
		{
			bPlayAgain = false;
		}
	}
	return 0;
}

// Implementations

void PrintIntroduction()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls & Cows, a fun game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << "-letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Maximum tries: " << MaxTries << std::endl;
	while (BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = ReadGuess();
		PrintGuess(Guess);
		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
	FText Response = "";
	std::cout << "Play again? ";
	std::getline(std::cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	else {
		return false;
	}
}

FText ReadGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "[Attempt " << CurrentTry << "] Enter your guess: ";
	std::getline(std::cin, Guess);
	BCGame.IncrementCurrentTry();
	return Guess;
}

void PrintGuess(FText g)
{
	std::cout << "You guessed: " << g << std::endl;
}