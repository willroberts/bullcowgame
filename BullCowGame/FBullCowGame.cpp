#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FString = std::string;

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{ 
	return MyMaxTries;
};

int32 FBullCowGame::GetCurrentTry() const 
{ 
	return MyCurrentTry;
};

FString FBullCowGame::GetHiddenWord() const
{
	return MyHiddenWord; 
};

int32 FBullCowGame::GetHiddenWordLen() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon(FString Guess) const 
{
	if (Guess == MyHiddenWord)
	{
		return true;
	}
	return false;
};

bool FBullCowGame::IsGuessValid(FString Guess) const
{
	if (Guess.length() == MyHiddenWord.length())
	{
		return true;
	}
	return false;
};

void FBullCowGame::IncrementCurrentTry()
{
	MyCurrentTry++;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	FBullCowCount BullCowCount;

	if (!IsGuessValid(Guess))
	{
		std::cout << "Invalid guess length!\n";
		return BullCowCount;
	}

	IncrementCurrentTry();
	auto WLen = MyHiddenWord.length();
	for (int32 WChar = 0; WChar < WLen; WChar++)
	{
		for (int32 GChar = 0; GChar < WLen; GChar++)
		{
			if (MyHiddenWord[WChar] == Guess[GChar])
			{
				if (WChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{	
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}

void FBullCowGame::Reset() {
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	return;
}