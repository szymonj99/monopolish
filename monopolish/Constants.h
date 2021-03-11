// Szymon Janusz G20792986

#pragma once
#include <string>

namespace GlobalConstants
{
	enum EExitCodes
	{
		SuccessFinish = 0,
		LevelFileFail = -50,
		SeedFileFail = -51,
		IncorrectLevelFile = -52,
	};

	enum ESquareType
	{
		Property = 1,
		Go,
		Station,
		Bonus,
		Penalty,
		Jail,
		GoToParking,
		FreeParking,
		None
	};

	enum ESquareColour
	{
		Red = 0,
		Grey,
		Brown,
		Orange,
		Yellow,
		Green,
		Blue,
		Purple,
		NONE
	};

	enum ESquareIndexes
	{
		Type = 0,
		FirstName,
		SecondName,
		Cost,
		Rent,
		ColourGroup,
		ThirdName = 3 // Used for "Go to Jail"
	};

	const int32_t kGO_COLLECTION = 200;
	const char kPOUND_SIGN = '£'; // 156 or 35 or 163
	const int32_t kROUNDS_TO_PLAY = 20;
	const int32_t kNUMBER_OF_SQUARES = 26;
}