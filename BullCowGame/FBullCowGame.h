#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame();

	int GetMaxTries() const;
	int GetCurrentTry() const;
	FString GetHiddenWord() const;
	bool IsGameWon() const;
	bool IsGuessValid(FString) const;

	void IncrementCurrentTry();
	FBullCowCount SubmitGuess(FString);
	void Reset();

private:
	int MyCurrentTry;
	int MyMaxTries;
	FString MyHiddenWord;
};