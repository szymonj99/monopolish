// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareJail.h"

CSquareJail::CSquareJail(const ESquareType kType, const std::string& kName)
{
	SetType(kType);
	SetName(kName);
}

bool CSquareJail::LandOnSquare(std::shared_ptr<CPlayer> player)
{
	std::cout << player->GetName() << " lands on " << GetName() << std::endl;
	std::cout << player->GetName() << " is just visiting" << std::endl;
	return true;
}