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
	int32 WordLen = BCGame.GetHiddenWordLen();
	std::cout << "Welcome to Bulls & Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WordLen;
	std::cout << "-letter isogram I'm thinking of?";
	std::cout << std::endl << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Maximum tries: " << MaxTries << std::endl;

	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = ReadGuess();
		auto BullCowCount = BCGame.SubmitGuess(Guess);

		if (BCGame.GetHiddenWordLen() == BullCowCount.Bulls)
		{
			std::cout << "The word was " << BCGame.GetHiddenWord() << "\n";
			std::cout << "You win!" << std::endl;
			return;
		}

		std::cout << "Bulls: " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows: " << BullCowCount.Cows << std::endl;

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
	return Guess;
}