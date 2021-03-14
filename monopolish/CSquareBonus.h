// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#pragma once
#include <vector>
#include "CSquare.h"

class CSquareBonus : public CSquare
{
private:
	using mBonusesVector_T = std::vector<std::pair<std::string, int32_t>>;
	using mBonus_T = std::pair<std::string, int32_t>;
	mBonusesVector_T mBonuses = 
	{
		{"Find Some money.", 20},
		{"Win a coding competition.", 50},
		{"Receive a rent rebate.", 100},
		{"Win the lottery.", 150},
		{"Receive a bequest.", 200},
		{"It's your birthday.", 300}
	};

public:
	CSquareBonus(const ESquareType kType, const std::string& kName);
	bool LandOnSquare(std::shared_ptr<CPlayer> player);
	mBonus_T GetBonus(const int32_t kRoll) const;
};

