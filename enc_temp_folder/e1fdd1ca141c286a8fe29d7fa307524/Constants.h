// Szymon Janusz G20792986

// Disable warning about truncation of value for the pound sign.
#pragma warning(disable: 4309)

#pragma once
#include <string>

namespace GlobalConstants
{
	enum class EExitCodes
	{
		SuccessFinish = 0,
		LevelFileFail = -50,
		SeedFileFail = -51,
		IncorrectLevelFile = -52,
	};

	enum class ESquareType
	{
		Property = 1,
		Go,
		Station,
		Bonus,
		Penalty,
		Jail,
		GoToJail,
		FreeParking,
		TotalTypes,
		NONE
	};

	enum class ESquareColour
	{
		Red = 0,
		Grey,
		Brown,
		Orange,
		Yellow,
		Green,
		Blue,
		Purple,
		TotalColours,
		NONE
	};

	enum class ESquareIndexes
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
	const char kPOUND_SIGN = 156; // 156 or 35 or 163
	const int32_t kROUNDS_TO_PLAY = 40;
	const int32_t kNUMBER_OF_SQUARES = 26;
	const int32_t kJAIL_PRICE = 50;
	const int32_t kSTATION_TICKET_PRICE = 10;
	const int32_t kSTATION_PRICE = 200;
}