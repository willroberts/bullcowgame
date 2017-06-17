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

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	FString GetHiddenWord() const;
	int32 GetHiddenWordLen() const;
	bool IsGameWon(FString) const;
	bool IsGuessValid(FString) const;

	void IncrementCurrentTry();
	FBullCowCount SubmitGuess(FString);
	void Reset();

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};