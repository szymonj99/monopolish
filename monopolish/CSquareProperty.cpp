// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareProperty.h"

CSquareProperty::CSquareProperty(const ESquareType kType, const std::string& kName, const int32_t kCost, const int32_t kRent, const ESquareColour kColour)
{
	SetType(kType);
	SetName(kName);
	SetCost(kCost);
	SetRent(kRent);
	SetSquareColour(kColour);
}

bool CSquareProperty::LandOnSquare(std::shared_ptr<CPlayer> player)
{
	std::cout << player->GetName() << " lands on " << GetName() << std::endl;

	// If the property doesn't have an owner
	if (GetPropertyOwner() == nullptr && player->GetMoney() > 0)
	{
		SetPropertyOwner(player);
		//player->AddProperty(this);
		player->SubtractMoney(GetCost());
		std::cout << player->GetName() << " buys " << GetName() << " for " << GlobalConstants::kPOUND_SIGN << GetCost() << std::endl;
	}

	// If the property is purchased by someone that isn't the player
	if (GetPropertyOwner() != nullptr && GetPropertyOwner() != player)
	{
		player->SubtractMoney(GetRent());
		GetPropertyOwner()->AddMoney(GetRent());
		std::cout << player->GetName() << " pays " << GlobalConstants::kPOUND_SIGN << GetRent() << std::endl;

		////if (kGameManager.PlayerOwnsAllPropertyOfColour(player, GetSquareColour()))
		//{
		//	player->SubtractMoney(GetRent() * 2);
		//	GetPropertyOwner()->AddMoney(GetRent() * 2);
		//	std::cout << player->GetName() << " pays " << GlobalConstants::kPOUND_SIGN << GetRent() * 2<< std::endl;
		//}
		//else
		//{
		//	}		
	}
	
	return true;
}