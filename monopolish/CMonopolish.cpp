// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include <sstream>
#include "CMonopolish.h"
#include "CSquareProperty.h"
#include "CSquareGo.h"
#include "CSquareStation.h"
#include "CSquareBonus.h"
#include "CSquarePenalty.h"
#include "CSquareFreeParking.h"
#include "CSquareGoToJail.h"
#include "CSquareJail.h"
#include "Constants.h"
#include "CPlayer.h"

// Get rid of the namespace to clean up the code.
using GlobalConstants::ESquareType;
using GlobalConstants::EExitCodes;
using GlobalConstants::ESquareIndexes;
using GlobalConstants::kNUMBER_OF_SQUARES;
using GlobalConstants::kROUNDS_TO_PLAY;
using GlobalConstants::kPOUND_SIGN;

// Set up the member vector variable that stores the squares.
bool CMonopolish::LoadSquares(const std::string& kFileName = "monopoly.txt")
{
	std::ifstream inputStream(kFileName);

	if (!inputStream)
	{
		std::cout << "Error: level file can't be opened: " << kFileName << "\n";
		std::cout << "Press enter to exit.";
		std::cin.get();
		std::exit((int32_t)EExitCodes::LevelFileFail);
	}

	// Make sure we have enough memory in the vector
	// To prevent copying multiple objects repeatedly
	mSquares.clear();
	mSquares.reserve(kNUMBER_OF_SQUARES);

	// Read every line, then parse it.
	std::string currentLine;
	while (getline(inputStream, currentLine))
	{
		// Parse the line one-by-one
		std::istringstream stringStream(currentLine);
		std::string word;
		std::vector<std::string> lineMembers;
		while (stringStream >> word)
		{
			lineMembers.emplace_back(word);
		}
		
		int32_t currentSquareType = static_cast<int32_t>(std::stoi(lineMembers.at((int32_t)ESquareIndexes::Type)));
		const ESquareType kType = static_cast<ESquareType>(currentSquareType);
		// Parse the current square type to int
		switch (currentSquareType)
		{
		case (int32_t)ESquareType::Property:
		{
			const std::string kName = lineMembers.at((int32_t)ESquareIndexes::FirstName) + " " +
				lineMembers.at((int32_t)ESquareIndexes::SecondName);
			const int32_t kCost = static_cast<int32_t>(std::stoi(lineMembers.at((int32_t)ESquareIndexes::Cost)));
			const int32_t kRent = static_cast<int32_t>(std::stoi(lineMembers.at((int32_t)ESquareIndexes::Rent)));
			const ESquareColour kColour = static_cast<ESquareColour>(std::stoi(lineMembers.at((int32_t)ESquareIndexes::ColourGroup)));
		
			mSquares.push_back(std::make_shared<CSquareProperty>(kType, kName, kCost, kRent, kColour));
			break;
		}
		case (int32_t)ESquareType::Go:
		{
			const std::string kName = lineMembers.at((int32_t)ESquareIndexes::FirstName);

			mSquares.push_back(std::make_shared<CSquareGo>(kType, kName));
			break;
		}
		case (int32_t)ESquareType::Station:
		{
			const std::string kName = lineMembers.at((int32_t)ESquareIndexes::FirstName) + " " + lineMembers.at((int32_t)ESquareIndexes::SecondName);

			mSquares.push_back(std::make_shared<CSquareStation>(kType, kName));
			break;
		}
		case (int32_t)ESquareType::Bonus:
		{
			const std::string kName = lineMembers.at((int32_t)ESquareIndexes::FirstName);

			mSquares.push_back(std::make_shared<CSquareBonus>(kType, kName));
			break;
		}
		case (int32_t)ESquareType::Penalty:
		{
			const std::string kName = lineMembers.at((int32_t)ESquareIndexes::FirstName);

			mSquares.push_back(std::make_shared<CSquarePenalty>(kType, kName));
			break;
		}
		case (int32_t)ESquareType::Jail:
		{
			const std::string kName = lineMembers.at((int32_t)ESquareIndexes::FirstName);

			mSquares.push_back(std::make_shared<CSquareJail>(kType, kName));
			break;
		}
		case (int32_t)ESquareType::GoToJail:
		{
			const std::string kName =
				lineMembers.at((int32_t)ESquareIndexes::FirstName) + " " +
				lineMembers.at((int32_t)ESquareIndexes::SecondName) + " " +
				lineMembers.at((int32_t)ESquareIndexes::ThirdName);

			mSquares.push_back(std::make_shared<CSquareGoToJail>(kType, kName));
			break;
		}
		case (int32_t)ESquareType::FreeParking:
		{
			const std::string kName =
				lineMembers.at((int32_t)ESquareIndexes::FirstName) + " " +
				lineMembers.at((int32_t)ESquareIndexes::SecondName);

			mSquares.push_back(std::make_shared<CSquareFreeParking>(kType, kName));
			break;
		}
		default:
		{
			// Handle error here when the line doesn't match any square types.
			std::cout << "Error when loading file. Press Enter to exit." << std::endl;
			std::cin.get();
			std::exit((int32_t)EExitCodes::LevelFileFail);
		}
		}
	}

	return true;
}

// Set up the member vector variable that stores the players.
bool CMonopolish::SetUpPlayers()
{
	mPlayers.clear();
	const int16_t kMaxPlayers = 2;
	mPlayers.reserve(kMaxPlayers);
	mPlayers.emplace_back(std::make_unique<CPlayer>("Dog"));
	mPlayers.emplace_back(std::make_unique<CPlayer>("Car"));
	return true;
}

// Read the seed (first item) in from file.
int64_t CMonopolish::GetSeed(const std::string& kSeedFile = "seed.txt")
{
	std::ifstream inputStream(kSeedFile);

	if (!inputStream)
	{
		std::cout << "Error: seed file can't be opened: " << kSeedFile << "\n";
		std::cout << "Press enter to exit.";
		std::cin.get();
		std::exit((int32_t)EExitCodes::SeedFileFail);
	}

	int64_t seed;
	inputStream >> seed;
	return seed;
}

// Initialise the pseudo-random generator with a seed.
bool CMonopolish::SetUpRandom()
{
	std::srand(static_cast<unsigned int>(GetSeed()));
	return true;
}

// Print the welcome message the user sees at the beginning of the game.
bool CMonopolish::PrintWelcomeMessage()
{
	const std::string kMsg = "Welcome to Monopol-ish";
	std::cout << kMsg << "\n";
	return true;
}

// Play the game.
bool CMonopolish::PlayGame()
{
	for (mCurrentRound = 0; mCurrentRound < kROUNDS_TO_PLAY; mCurrentRound++)
	{
		// Player rolls number here
		for (int16_t playerIndex = 0; playerIndex < mPlayers.size(); playerIndex++)
		{
			const auto kPlayerRoll = mPlayers.at(playerIndex)->RollNumber();
			std::cout << mPlayers.at(playerIndex)->GetName() << " rolls " << kPlayerRoll << std::endl;
			mPlayers.at(playerIndex)->MoveForward(kPlayerRoll);
			mSquares.at(mPlayers.at(playerIndex)->GetPosition())->LandOnSquare(mPlayers.at(playerIndex));
			std::cout << mPlayers.at(playerIndex)->GetName() << " has " << kPOUND_SIGN << mPlayers.at(playerIndex)->GetMoney() << std::endl;
		}
	}

	std::cout << "Game Over\n";
	for (int16_t i = 0; i < mPlayers.size(); i++)
	{
		std::cout << mPlayers.at(i)->GetName() << " has " << kPOUND_SIGN << mPlayers.at(i)->GetMoney() << "\n";
	}
	std::cout << GetWinningPlayer() << " wins." << std::endl;

	return true;
}

// Get the name of the winning player (Player with the most money).
std::string CMonopolish::GetWinningPlayer() const
{
	auto currentMax = mPlayers.at(0)->GetMoney();
	std::string winningPlayer = mPlayers.at(0)->GetName();

	for (int16_t i = 1; i < mPlayers.size(); i++)
	{
		if (mPlayers.at(i)->GetMoney() > currentMax)
		{
			currentMax = mPlayers.at(i)->GetMoney();
			winningPlayer = mPlayers.at(i)->GetName();
		}
	}

	return winningPlayer;
}

// Set up the game and play until game is over.
bool CMonopolish::StartGame()
{
	PrintWelcomeMessage();
	SetUpRandom();
	LoadSquares();
	SetUpPlayers();

	PlayGame();

	return true;
}