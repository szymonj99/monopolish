// Szymon Janusz G20792986

#pragma once
#include "CSquare.h"
#include "Constants.h"

class CSquareProperty : public CSquare
{
public:
	CSquareProperty(const ESquareType kType, const std::string& kName, const int32_t kCost, const int32_t kRent, const ESquareColour kColour);
	bool LandOnSquare(std::shared_ptr<CPlayer> player);
};

