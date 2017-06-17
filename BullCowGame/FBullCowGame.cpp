#pragma once
#include <iostream>
#include <map>
#include <string>
#include "FBullCowGame.h"

// Unreal Engine helpers.
#define TMap std::map
using FString = std::string;

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	// Use the word length for the number of tries.
	// TODO: Use a scaling function which matches TMap.
	TMap<int32, int32> WLenToMaxTries{
		{3,4},
		{4,7},
		{5,10},
		{6,16},
		{7,20}
	};
	return GetHiddenWordLen();
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

bool FBullCowGame::IsGameWon() const 
{
	return bGameIsWon;
};

EWordStatus FBullCowGame::IsGuessValid(FString Guess) const
{
	// Determine if the guess has the correct length.
	if (Guess.length() != MyHiddenWord.length())
	{
		return EWordStatus::InvalidLength;
	}

	// Determine if the guess is an isogram.
	TMap<char, bool> LetterSeen;
	for (const char c : Guess)
	{
		if (LetterSeen[c] == true) {
			return EWordStatus::NotIsogram;
		}
		LetterSeen[c] = true;
	}

	return EWordStatus::OK;
};

void FBullCowGame::IncrementCurrentTry()
{
	MyCurrentTry++;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	IncrementCurrentTry();
	FBullCowCount BullCowCount;

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

	// Detect victory.
	if (WLen == BullCowCount.Bulls)
	{
		bGameIsWon = true;
	}

	return BullCowCount;
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	bGameIsWon = false;

	return;
}