// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareStation.h"

CSquareStation::CSquareStation(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquareStation::LandOnSquare(std::shared_ptr<CPlayer> player)
{
	std::cout << player->GetName() << " lands on " << GetName() << std::endl;

	// If the property doesn't have an owner
	if (GetPropertyOwner() == nullptr && player->GetMoney() > 0)
	{
		SetPropertyOwner(player);
		player->SubtractMoney(GlobalConstants::kSTATION_PRICE);
		std::cout << player->GetName() << " buys " << GetName() << " for " << GlobalConstants::kPOUND_SIGN << GlobalConstants::kSTATION_PRICE << std::endl;
	}

	// If the property is purchased by someone that isn't the player
	if (GetPropertyOwner() != nullptr && GetPropertyOwner() != player)
	{
		player->SubtractMoney(GlobalConstants::kSTATION_TICKET_PRICE);
		GetPropertyOwner()->AddMoney(GlobalConstants::kSTATION_TICKET_PRICE);
		std::cout << player->GetName() << " pays " << GlobalConstants::kPOUND_SIGN << GlobalConstants::kSTATION_TICKET_PRICE << " for ticket" << std::endl;
	}

	return true;
}