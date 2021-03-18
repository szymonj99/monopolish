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
	std::cout << player->GetName() << " lands on " << this->GetName() << std::endl;

	// If the property doesn't have an owner
	if (GetPropertyOwner() == nullptr && player->GetMoney() > 0)
	{
		SetPropertyOwner(player);
		player->AddOwnedPropertyIndex(this->GetIndex());
		player->SubtractMoney(GetCost());
		std::cout << player->GetName() << " buys " << this->GetName() << " for " << GlobalConstants::kPOUND_SIGN << GetCost() << std::endl;
	}

	// If the property is purchased by someone that isn't the player
	if (!IsMortgaged() && GetPropertyOwner() != nullptr && GetPropertyOwner() != player)
	{
		int32_t multiplier = 1;
		// Gotta love hard-coded values
		// The vector stores how many total properties there are for each colour
		// The index represents ESquareColour.
		const std::vector<uint32_t> kPropertyCountByColour{ 2,2,2,3,2,2,3,2 };
		// Check if the property owner owns all properties of this colour
		if(GetPropertyOwner()->GetOwnedColouredPropertyCount(GetSquareColour()) == kPropertyCountByColour.at((int32_t)GetSquareColour()))
		{
			// Doubling rent if the player lands on a property that's owned by someone else, that owns all properties of that colour
			multiplier = 2;
		}
		player->SubtractMoney(GetRent() * multiplier);
		GetPropertyOwner()->AddMoney(GetRent() * multiplier);
		std::cout << player->GetName() << " pays " << GlobalConstants::kPOUND_SIGN << GetRent() * multiplier << " to " << GetPropertyOwner()->GetName() << std::endl;
	}
	
	return true;
}