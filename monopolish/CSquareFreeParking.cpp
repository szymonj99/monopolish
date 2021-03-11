// Szymon Janusz G20792986

#include "CSquareFreeParking.h"

CSquareFreeParking::CSquareFreeParking(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquareFreeParking::LandOnSquare(std::unique_ptr<CPlayer> player)
{
	return true;
}