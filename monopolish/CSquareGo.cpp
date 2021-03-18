// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareGo.h"

CSquareGo::CSquareGo(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquareGo::LandOnSquare(std::shared_ptr<CPlayer> player)
{
	return true;
}