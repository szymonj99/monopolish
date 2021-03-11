// Szymon Janusz G20792986

#pragma once
#include "CSquare.h"

class CSquareJail : public CSquare
{
public:
	CSquareJail(const ESquareType kType, const std::string& kName);
	bool LandOnSquare(std::shared_ptr<CPlayer> player);
};
