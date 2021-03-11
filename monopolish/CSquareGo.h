// Szymon Janusz G20792986

#pragma once
#include "CSquare.h"

class CSquareGo : public CSquare
{
public:
	CSquareGo(const ESquareType kType, const std::string& kName);
	bool LandOnSquare(std::shared_ptr<CPlayer> player);
};
