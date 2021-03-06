// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquarePenalty.h"

CSquarePenalty::CSquarePenalty(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquarePenalty::LandOnSquare(std::shared_ptr<CPlayer> player)
{
	std::cout << player->GetName() << " lands on " << this->GetName() << std::endl;
	auto penalty = GetPenalty(Random()); 
	std::cout << penalty.first << " Lose " << GlobalConstants::kPOUND_SIGN << penalty.second << std::endl;
	player->SubtractMoney(penalty.second);
	return true;
}

CSquarePenalty::mPenalty_T CSquarePenalty::GetPenalty(const int32_t kRoll) const
{
	// We roll 1 - 6, indexes go from 0 - 5.
	return mPenalties.at(kRoll - 1);
}