#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Unreal Engine helpers.
using int32 = int;
using FText = std::string;

void PrintIntroduction();
void PlayGame();
bool AskToPlayAgain();
FText ReadGuess();

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

void PrintIntroduction()
{
	int32 WordLen = BCGame.GetHiddenWordLen();
	std::cout << "Welcome to Bulls & Cows, a fun word game.\n";
	std::cout << "A \"bull\" is a correct letter in the correct position.\n";
	std::cout << "A \"cow\" is a correct letter in the wrong position.\n" << std::endl;
	
	std::cout << "    ^__^\n";
	std::cout << "    (oo)\\_______\n";
	std::cout << "    (__)\\       )\\ / \\\n";
	std::cout << "        ||----w |\n";
	std::cout << "        ||     ||\n" << std::endl;

	std::cout << "Can you guess the " << WordLen << "-letter isogram I'm thinking of?\n";
	std::cout << "An isogram is a word with no repeating letters.\n" << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = ReadGuess();
		auto BullCowCount = BCGame.SubmitGuess(Guess);

		if (BCGame.IsGameWon())
		{
			std::cout << "The word was " << BCGame.GetHiddenWord() << "\n";
			std::cout << "You win!" << std::endl;
			return;
		}

		std::cout << "Bulls: " << BullCowCount.Bulls << ", ";
		std::cout << "Cows: " << BullCowCount.Cows << "\n" << std::endl;
	}

	std::cout << "You lose!" << std::endl;
	//std::cout << "The word was " << BCGame.GetHiddenWord() << std::endl;
}

bool AskToPlayAgain()
{
	FText Response = "";
	std::cout << "Play again? [y/n] ";
	std::getline(std::cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y')
	{
		return true;
	}
	else {
		return false;
	}
}

FText ReadGuess()
{
	bool bValid = false;
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	while (!bValid)
	{
		std::cout << "[Attempt " << CurrentTry;
		std::cout << " of " << BCGame.GetMaxTries() << "] ";
		std::cout << "Enter your guess : ";
		std::getline(std::cin, Guess);

		switch (BCGame.IsGuessValid(Guess))
		{
		case EWordStatus::InvalidLength:
			std::cout << "Invalid guess length!\n";
			break;
		case EWordStatus::NotIsogram:
			std::cout << "Word is not an isogram!\n";
			break;
		default:
			bValid = true;
			break;
		}
	}

	// Convert Guess to lowercase.
	std::transform(Guess.begin(), Guess.end(), Guess.begin(), ::tolower);
	return Guess;
}