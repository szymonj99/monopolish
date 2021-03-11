// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#pragma once
#include <vector>
#include "CSquare.h"

class CSquarePenalty : public CSquare
{
private:
	std::vector<std::pair<std::string, int32_t>> mPenalties =
	{
		{"Buy a coffee in Starbucks.", 20},
		{"Pay your broadband bill.", 50},
		{"Visit the SU shop for food.", 100},
		{"Buy an assignment solution.", 150},
		{"Go for a romantic meal.", 200},
		{"Pay some university fees.", 300}
	};

public: 
	CSquarePenalty(const ESquareType kType, const std::string& kName);
	bool LandOnSquare(std::shared_ptr<CPlayer> player);
	std::pair<std::string, int32_t> GetPenalty(const int32_t kRoll) const;
};

