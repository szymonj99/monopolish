// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#pragma once
#include "CSquare.h"

class CSquareBonus : public CSquare
{
public:
	CSquareBonus(const ESquareType kType, const std::string& kName);
	bool LandOnSquare(std::unique_ptr<CPlayer> player);
};

