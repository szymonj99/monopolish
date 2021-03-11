// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include <sstream>
#include "CMonopolish.h"
#include "CSquareProperty.h"
#include "CSquareGo.h"
#include "CSquareFreeParking.h"
#include "CSquareJail.h"
#include "Constants.h"
#include "CPlayer.h"

// Get rid of the namespace to clean up the code.
using GlobalConstants::ESquareType;
using GlobalConstants::EExitCodes;
using GlobalConstants::ESquareIndexes;
using GlobalConstants::kNUMBER_OF_SQUARES;

bool CMonopolish::LoadSquares(const std::string& kFileName = "monopoly.txt")
{
	std::ifstream inputStream(kFileName);

	if (!inputStream)
	{
		std::cout << "Error: level file can't be opened: " << kFileName << "\n";
		std::cout << "Press enter to exit.";
		std::cin.get();
		std::exit(EExitCodes::LevelFileFail);
	}

	// Make sure we have enough memory in the vector
	// To prevent copying multiple objects repeatedly
	//mSquares = std::vector<std::unique_ptr<CSquare>>(kNUMBER_OF_SQUARES);
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
		
		int32_t currentSquareType = static_cast<int32_t>(std::stoi(lineMembers.at(ESquareIndexes::Type)));
		const ESquareType kType = static_cast<ESquareType>(currentSquareType);
		// Parse the current square type to int
		switch (currentSquareType)
		{
		case ESquareType::Property:
		{
			const std::string kName = lineMembers.at(ESquareIndexes::FirstName) + " " + lineMembers.at(ESquareIndexes::SecondName);
			const int32_t kCost = static_cast<int32_t>(std::stoi(lineMembers.at(ESquareIndexes::Cost)));
			const int32_t kRent = static_cast<int32_t>(std::stoi(lineMembers.at(ESquareIndexes::Rent)));
			const ESquareColour kColour = static_cast<ESquareColour>(std::stoi(lineMembers.at(ESquareIndexes::ColourGroup)));

			//auto test = std::make_shared<CSquareProperty>(kType, kName, kCost, kRent, kColour);

			CSquareProperty* test = new CSquareProperty();

			//mSquares.emplace_back(std::make_unique<CSquareProperty>(kType, kName, kCost, kRent, kColour));

			//mSquares.emplace_back(std::move(test));
			//mSquares.emplace_back(std::make_shared<CSquareProperty>(kType, kName, kCost, kRent, kColour));

			//mSquares.emplace_back(new CSquareProperty(kType, kName, kCost, kRent, kColour));

			//auto test2 = std::make_unique<CSquareProperty>();
			//test->2

			//squares.push_back(std::move(test));
			//squares.emplace_back(std::move(test));

			//std::unique_ptr<CSquare> test2 = std::make_unique<CSquareProperty>(kType, kName, kCost, kRent, kColour);

			//squares.push_back(std::move(test));

			//squares.
			//test->GetCost();

			//squares.emplace_back(std::move(test));

			//squares.emplace_back(new CSquareProperty(kType, kName, kCost, kRent, kColour));
			//squares.push_back(std::move(test));

			//squares.emplace_back(std::make_shared<CSquareProperty>(kType, kName, kCost, kRent, kColour));

			//squares.push_back(test);

			//squares.emplace_back(new CSquareProperty(kType, kName, kCost, kRent, kColour));
			break;
		}
		case ESquareType::Go:
		{
			const std::string kName = lineMembers.at(ESquareIndexes::FirstName);
			//squares.emplace_back(new CSquareGo(kType, kName));
			break;
		}
		default:
		{
			// Handle error here when the line doesn't match any square types.
			break;
		}
		}
	}

	//while (!inputStream.eof())
	//{
	//	int32_t item = INT32_MIN;
	//	inputStream >> item;
	//	
	//	// First item is the square type
	//	switch (item)
	//	{
	//	case ESquareType::Property:
	//	{
	//		std::string name;
	//		int32_t cost, rent;

	//		std::istringstream stringStream()

	//		std::unique_ptr<CSquare> prop = std::make_unique<CSquareProperty>(name, cost, rent, ESquareColour::Blue);
	//		squares.push_back(prop);

	//		break;
	//	}
	//	case ESquareType::Go:
	//	{
	//		break;
	//	}
	//	case ESquareType::Station:
	//	{
	//		break;
	//	}
	//	case ESquareType::Bonus:
	//	{
	//		break;
	//	}
	//	case ESquareType::Penalty:
	//	{
	//		break;
	//	}
	//	case ESquareType::Jail:
	//	{
	//		break;
	//	}
	//	case ESquareType::GoToParking:
	//	{
	//		break;
	//	}
	//	case ESquareType::FreeParking:
	//	{
	//		break;
	//	}

	//	default:
	//	{
	//		std::cout << "Incorrect level file format." << std::endl;
	//		std::cin.get();
	//		exit(EExitCodes::IncorrectLevelFile);
	//	}
	//	}

	//	squares.emplace_back(std::make_unique<CSquare>("Test"));
	//}

	return true;
}

// Read the seed (first item) in from file.
int64_t GetSeed(const std::string& SEED_FILE = "seed.txt")
{
	std::ifstream inputStream(SEED_FILE);

	if (!inputStream)
	{
		std::cout << "Error: seed file can't be opened: " << SEED_FILE << "\n";
		std::cout << "Press enter to exit.";
		std::cin.get();
		std::exit(EExitCodes::SeedFileFail);
	}

	int64_t seed;
	inputStream >> seed;
	return seed;
}

// Initialise the pseudo-random generator with a seed.
bool SetUpRandom()
{
	std::srand(static_cast<unsigned int>(GetSeed()));
	return true;
}

bool PrintWelcomeMessage()
{
	const std::string kMsg = "Welcome to Monopol-ish";
	std::cout << kMsg << "\n";
	return true;
}

bool CMonopolish::StartGame()
{
	PrintWelcomeMessage();
	SetUpRandom();
	std::vector<std::unique_ptr<CSquare>> squares(kNUMBER_OF_SQUARES);
	LoadSquares("monopoly.txt");

	//SetUpPlayers();


	return true;
}