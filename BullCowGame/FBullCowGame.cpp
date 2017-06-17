#include <string>
#include "FBullCowGame.h"

using FString = std::string;

FBullCowGame::FBullCowGame() {
	Reset();
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; };
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; };
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; };
bool FBullCowGame::IsGameWon() const { return false; };
bool FBullCowGame::IsGuessValid(FString) const { return false; };

void FBullCowGame::IncrementCurrentTry() {
	MyCurrentTry++;
}

FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	IncrementCurrentTry();
	FBullCowCount BullCowCount;
	// FIXME: Continue here from 2.36.
	// Iterate through Guess.
	// Compare letters to hidden word.
	// If they match, increment bulls/cows
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