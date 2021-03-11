// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareBonus.h"

CSquareBonus::CSquareBonus(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquareBonus::LandOnSquare(std::unique_ptr<CPlayer> player)
{
	return true;
}