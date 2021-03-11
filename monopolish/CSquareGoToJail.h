// Szymon Janusz G20792986

#pragma once
#include "CSquare.h"

class CSquareGoToJail : public CSquare
{
public:
	CSquareGoToJail(const ESquareType kType, const std::string& kName);
	bool LandOnSquare(std::unique_ptr<CPlayer> player);
};
