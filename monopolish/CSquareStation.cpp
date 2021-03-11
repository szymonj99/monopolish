// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareStation.h"

CSquareStation::CSquareStation(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquareStation::LandOnSquare(std::unique_ptr<CPlayer> player)
{
	return true;
}