#pragma once
#include <string>

// Unreal Engine helpers.
using int32 = int;
using FString = std::string;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

/* EWordStatus stores the result of guess validation.
*/
enum class EWordStatus
{
	OK,
	InvalidLength,
	NotIsogram
};

/* FullCowGame represents our game state and logic.
*/
class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	FString GetHiddenWord() const;
	int32 GetHiddenWordLen() const;
	bool IsGameWon() const;
	EWordStatus IsGuessValid(FString) const;

	void IncrementCurrentTry();
	FBullCowCount SubmitGuess(FString);
	void Reset();

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
};