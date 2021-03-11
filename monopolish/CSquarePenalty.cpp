// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquarePenalty.h"

CSquarePenalty::CSquarePenalty(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquarePenalty::LandOnSquare(std::unique_ptr<CPlayer> player)
{
	return true;
}