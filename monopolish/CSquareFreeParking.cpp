// Szymon Janusz G20792986

#include "CSquareFreeParking.h"

CSquareFreeParking::CSquareFreeParking(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquareFreeParking::LandOnSquare(std::shared_ptr<CPlayer> player)
{
	std::cout << player->GetName() << " lands on " << this->GetName() << std::endl;
	std::cout << player->GetName() << " is resting" << std::endl;
	return true;
}