// Szymon Janusz G20792986

#pragma once
#include "CSquare.h"
#include "Constants.h"

class CSquareProperty : protected CSquare
{
public:
	CSquareProperty() {};
	//~CSquareProperty() {};
	CSquareProperty(const ESquareType kType, const std::string& kName, const int32_t kCost, const int32_t kRent, const ESquareColour kColour);
	//int32_t GetCost() const;
	//bool SetCost(const int32_t kCost);
	//int32_t GetRent() const;
	//bool SetRent(const int32_t kRent);
	//ESquareColour GetSquareColour() const;
	//bool SetSquareColour(const ESquareColour kColour);
	//std::shared_ptr<CPlayer> GetPropertyOwner() const;
	//bool SetPropertyOwner(std::shared_ptr<CPlayer> player);
	//bool IsOwnedByPlayer(const std::shared_ptr<CPlayer> player);

	bool LandOnSquare(std::unique_ptr<CPlayer> player);
};

