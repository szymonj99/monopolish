// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#pragma once
#include <vector>
#include "CSquare.h"

class CSquareBonus : public CSquare
{
private:
	std::vector<std::pair<std::string, int32_t>> mBonuses = 
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
	std::pair<std::string, int32_t> GetBonus(const int32_t kRoll) const;
};

