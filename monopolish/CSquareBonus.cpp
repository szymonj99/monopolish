// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareBonus.h"

CSquareBonus::CSquareBonus(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquareBonus::LandOnSquare(std::shared_ptr<CPlayer> player)
{
	std::cout << player->GetName() << " lands on " << this->GetName() << std::endl;
	auto bonus = GetBonus(Random());
	std::cout << bonus.first << " Gain " << GlobalConstants::kPOUND_SIGN << bonus.second << std::endl;
	player->AddMoney(bonus.second);
	return true;
}

CSquareBonus::mBonus_T CSquareBonus::GetBonus(const int32_t kRoll) const
{
	// We roll 1 -6, indexes go from 0 - 5.
	return mBonuses.at(kRoll - 1);
}