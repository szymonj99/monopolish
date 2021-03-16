// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareGoToJail.h"

CSquareGoToJail::CSquareGoToJail(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquareGoToJail::LandOnSquare(std::shared_ptr<CPlayer> player)
{
	std::cout << player->GetName() << " lands on " << this->GetName() << std::endl;
	std::cout << player->GetName() << " goes to Jail" << std::endl;
	std::cout << player->GetName() << " pays " << GlobalConstants::kPOUND_SIGN << GlobalConstants::kJAIL_PRICE <<  std::endl;
	player->SubtractMoney(GlobalConstants::kJAIL_PRICE);
	player->GoToJail();

	return true;
}